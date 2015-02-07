/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_init_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 11:45:28 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/07 11:45:30 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm_compil.h"

int 	init_start(char **av)
{
	t_asm	*d;

	d = getASMdata();
	if (d == NULL)
	{
		ft_putendl_fd(ERR_INIT_MEM, 2);
		return (-1);
	}
	d->fdSource = open(av[1], O_RDONLY);
	if (d->fdSource < 0)
	{
		ft_putendl_fd(ERR_FILE_OPEN, 2);
		return (-1);
	}
	return (0);
}