/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 13:44:48 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/14 19:56:17 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm.h"
#include "libft.h"

static int	add_line(t_file *file, char *str, int i)
{
	t_line	*line;

	if (!(line = (t_line *)malloc(sizeof(t_line))))
		return (EXIT_FAILURE);
	line->id = i;
	line->str = ft_strdup(str);
	line->len = ft_strlen(line->str);
	line->type = 0;
	line->tokens = NULL;
	//line->inst.opcode = -1;
	//line->inst.parambyte = -1;

	line->pcode = -1;
	line->bytecode = NULL;
	//ft_bzero(line->param, sizeof(int) * 4);
	//ft_bzero(line->param_types, sizeof(int) * 4);
	ft_lstadd_back(&(file->lines), ft_lstnew((void *)line, sizeof(t_line)));
	free(line);
	return (EXIT_SUCCESS);
}

int			read_file(t_file *file)
{
	int		i;
	char	*str;

	//fprintf(stderr, "TEST2a\n");
	str = NULL;
	file->lines = NULL;
	i = 0;
	while ((file->ret = get_next_line(file->fd_s, &str)) > 0 || *str)
	{
		if (str && !(*str))
		{
			free(str);
			continue ;
		}
		//fprintf(stderr, "TEST2b - i=%d\n", i);
		if (add_line(file, str, i))
			return (EXIT_FAILURE);
		free(str);
		++i;
	}
	//fprintf(stderr, "TEST2c\n");
	if (file->ret == -1)
		return (EXIT_FAILURE);
	free(str);
	file->nb_line = i;
	if (i == 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
