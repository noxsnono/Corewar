/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:13:52 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/23 20:59:36 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "asm.h"
#include "asm_fn.h"
#include "libft.h"

static void	write_magic(int fd)
{
	int	magic;

	magic = COREWAR_EXEC_MAGIC;
	magic = ((magic >> 24) & 0xff) | ((magic << 8) & 0xff0000) |
		((magic >> 8) & 0xff00) | ((magic << 24) & 0xff000000);
	write(fd, (char *)&magic, 4);
	return ;
}

static void	write_name_comment(int fd, t_header header)
{
	char	buf[12];

	ft_bzero(buf, 8);
	write(fd, header.prog_name, PROG_NAME_LENGTH);
	write(fd, buf, 8);
	write(fd, header.comment, COMMENT_LENGTH);
	write(fd, buf, 4);
	return ;
}

static void	write_text_section(t_file *file)
{
	t_list	*tmp;
	//virer
	size_t	cuml=0;

	tmp = file->lines;
	fprintf(stderr, "WRITE:\n");

	while (tmp)
	{
		cuml+=LINE->code_len; //virer
		if (LINE->bytecode)
			write(file->fd_cor, LINE->bytecode, LINE->code_len);
		fprintf(stderr, "id: %d, str = \033[33m%s\033[0m, len = \033[31m%d\033[0m-\033[31m%d\033[0m line = |\033[1;34m", (int)LINE->id, LINE->str, (int)LINE->code_len, (int)cuml);

		int i = 0;
		while (i < (int)LINE->code_len)
			fprintf(stderr, "%d ", (LINE->bytecode)[i++]);
		fprintf(stderr, "\033[0m|\n");

		tmp = tmp->next;
	}
}

void		write_cor(t_file *file)
{
	fprintf(stderr, "file nb=%d\n", (int)file->nb_line);
	if (file->nb_line == 0)
		asm_error("No instruction in the file.\n");
	if (!(file->fd_cor = open(file->name_cor, O_WRONLY | O_CREAT, 0644)))
		asm_error("Couldln't create the .cor file.\n");
	write_magic(file->fd_cor);
	write_name_comment(file->fd_cor, file->header);
	write_text_section(file);
}
