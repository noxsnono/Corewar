/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/09 14:45:03 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** need test
** T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG
** change carry ?
** has idx
*/
	
int		op_sti(t_data *d, t_header *player)
{
	int ret;
	unsigned int reg;
	int value;

	writeL("--- op_sti ---");
	if ((ret = getOpArgs(d, player)) < 0
		&& isValidRegister(ft_hex2Dec(player->opArgs[0])) < 0)
	{
		writeL("error in op_sti arg");
		// sleep(5);
		return (ret);
	}
	reg = ft_hex2Dec(player->opArgs[0]);

	if (ft_strncmp(&player->codage[2], "01", 2) == 0
		&& isValidRegister(ft_hex2Dec(player->opArgs[1])) >= 0)
		value = get_arg_int(player->reg[ft_hex2Dec(player->opArgs[1])]);
	else
		value = get_arg_int(player->opArgs[1]);

	if (ft_strncmp(&player->codage[4], "01", 2) == 0
		&& isValidRegister(ft_hex2Dec(player->opArgs[2])) >= 0)
		value += get_arg_int(player->reg[ft_hex2Dec(player->opArgs[2])]);
	else
		value += get_arg_int(player->opArgs[2]);
	value = get_arg_modulo(value - 1, IDX_MOD);
	changeMemVal(d, player->number, (player->indexPC + 1 + value + MEM_SIZE) % MEM_SIZE, player->reg[reg]);
	pcAdvance(d, player, ret);
	return (0);
}