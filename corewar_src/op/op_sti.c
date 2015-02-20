/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/20 11:30:32 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** not tested
** T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG
** change carry ?
*/

int		op_sti(t_data *d, t_header *player, int id)
{
	int ret;
	unsigned int reg;
	unsigned int value[2];

	// writeL("-----------");
	// writeL("-----------");
	// writeL("-----------");
	// writeL("run op_sti");
	// writeL(player->reg[1]);
	// writeL(ft_itoa(id));

	if ((ret = getOpArgs(d, id)) < 0)
	{
		writeL("error in op_sti arg");
		sleep(5);
		return (ret);
	}
	if (isValidRegister(ft_hex2Dec(player->opArgs[0])) < 0)
	{
		writeL("error in op_sti reg =");
		writeL(ft_itoa(ft_hex2Dec(player->opArgs[0])));
		sleep(5);
		return (ret);
	}
	// writeL("arg 0 content1");
	// writeL(player->opArgs[0]); // bug here for players 2
	reg = ft_hex2Dec(player->opArgs[0]);
	// writeL("reg");
	// writeL(ft_itoa(reg));
	if (ft_strncmp(&player->codage[2], "01", 2) == 0
		&& isValidRegister(ft_hex2Dec(player->opArgs[1])) < 0)
		value[0] = ft_hex2Dec(player->reg[ft_hex2Dec(player->opArgs[1])]);
	else
		value[0] = ft_hex2Dec(player->opArgs[1]);
	if (ft_strncmp(&player->codage[4], "01", 2) == 0
		&& isValidRegister(ft_hex2Dec(player->opArgs[2])) < 0)
		value[1] = ft_hex2Dec(player->reg[ft_hex2Dec(player->opArgs[2])]);
	else
		value[1] = ft_hex2Dec(player->opArgs[1]);
	// writeL("indexPC");
	// writeL(ft_itoa(player->indexPC));
	// writeL("+ val");
	// writeL(ft_itoa(value[0] + value[1]));
	// writeL("reg number");
	// writeL(ft_itoa(reg));
	// writeL("in  reg");
	// writeL(player->reg[reg]);
	changeMemVal(d, id, player->indexPC + 1 + (value[0] + value[1]) / 2, player->reg[reg]);
	// writeL("after changeMemVal");
	// writeL("player id:");
	// writeL(ft_itoa(id));
	pcAdvance(d, player, ret);
	// writeL("-----end------");
	// writeL("-----------");
	// writeL("-----------");
	// sleep(5);
	return (0);
}