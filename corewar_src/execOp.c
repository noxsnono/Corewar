/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execOp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:19:06 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/23 17:25:41 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		execOp(t_data *d)
{
	int player;

	player = 0;
	while (player < d->players)
	{
		// exec d->prog[player].nextOp for player if d->prog[player].wait == 0
		writeL("-----------");
		writeL("execOp");
		writeL(ft_itoa(d->prog[player].nextOp));
		writeL("wait");
		writeL(ft_itoa(d->prog[player].wait));
		writeL("codage");
		writeL(d->prog[player].codage);
		if ( d->prog[player].wait == 1)
		{
			// exec func
			writeL("playerNbr");
			writeL(ft_itoa(player));
			usleep(10000);
			g_opfunc[d->prog[player].nextOp].func(d, &d->prog[player], player);
			d->prog[player].wait--;
		}
		else if (d->prog[player].wait > 0)
			d->prog[player].wait--;
		player++;
	}
	// sleep(1);
	d->cycle++;
	return (0);
}