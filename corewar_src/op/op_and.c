/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/12 17:37:56 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** tested OK
** T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG
** change carry
*/

int		op_and(t_data *d, t_header *player)
{
	int ret;
	unsigned int reg;
	unsigned int value[2];
	char		str[REG_SIZE + 1];
	
	writeL("--- op_and ---");
	player->carry = false;
	if ((ret = getOpArgs(d, player)) < 0
		|| isValidRegister(ft_hex2Dec(player->opArgs[2])) < 0)
		return (ret);
	reg = ft_hex2Dec(player->opArgs[2]);
	if (ft_strncmp(player->codage, "01", 2) == 0
		&& isValidRegister(ft_hex2Dec(player->opArgs[0])) >= 0)
		value[0] = reg_to_int(d, player, ft_hex2Dec(player->opArgs[0]));
		// value[0] = ft_hex2Dec(player->reg[ft_hex2Dec(player->opArgs[0])]);
	else
		value[0] = ft_hex2Dec(player->opArgs[0]);
	if (ft_strncmp(&player->codage[2], "01", 2) == 0
		&& isValidRegister(ft_hex2Dec(player->opArgs[1])) >= 0)
		value[1] = reg_to_int(d, player, ft_hex2Dec(player->opArgs[1]));
		// value[1] = ft_hex2Dec(player->reg[ft_hex2Dec(player->opArgs[1])]);
	else
		value[1] = ft_hex2Dec(player->opArgs[1]);
	ft_bzero(player->reg[reg], REG_SIZE);
	ft_bzero(str, REG_SIZE + 1);
	ft_putHexBNbr(value[0] & value[1], str);
	str_to_reg(d, player, reg, str);
	// ft_strcpy(player->reg[reg], str);
	player->carry = true;
	pcAdvance(d, player, ret);
	return (0);
}