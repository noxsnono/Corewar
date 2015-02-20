/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pcAdvance.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:02:50 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/20 17:17:16 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	pcAdvance(t_data *d, t_header *player, int adv)
{
	// writeL("hello");
	// writeL("index:");
	// writeL(player->indexPC);
	player->PC->present = false;
	// writeL("hello1");
	player->indexPC = (player->indexPC + MEM_SIZE + adv + 1) % MEM_SIZE;
	// writeL("hello2");

	 writeL("index:");
	 writeL(player->indexPC);
	player->PC = &d->map[player->indexPC];
	// writeL("mem case after pcAdv");
	// writeL(player->PC->hex);
	// writeL("hello3");
	player->PC->present = true;
	// writeL("hello4");

}