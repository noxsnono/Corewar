/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/17 19:33:25 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_op_tab.h"

/*
** tested OK
** T_REG, T_IND | T_REG
** has idx (g_op_tab incorrect)
*/
static int	op_st_2(t_data *d, t_header *player, int *value)
{
	if (is_register(player, 1) >= 0)
		(*value) = reg_to_int(d, player,
			get_int_from_dec((char *)player->op_args[1], T_LAB));
	else if (is_indirect(player, 1) >= 0)
	{
		(*value) = get_int_from_dec((char *)player->op_args[1], T_LAB);
		if (player->op_args[1][T_LAB - 2] >= 240)
			(*value) = (*value) - 65536;
		(*value) = get_arg_modulo((*value), IDX_MOD);
	}
	else
		return (-1);
	return (0);
}

int			op_st(t_data *d, t_header *player)
{
	int				ret;
	unsigned int	reg;
	int				value;

	player->carry = false;
	if ((ret = get_op_args(d, player)) < 0
		|| is_valid_register(get_int_from_dec((char *)player->op_args[0],
			T_LAB)) < 0)
		return (ret);
	reg = get_int_from_dec((char *)player->op_args[0], T_LAB);
	if (op_st_2(d, player, &value) < 0)
		return (-1);
	value = get_arg_modulo(value, IDX_MOD);
	change_mem_val(d, player->number, (player->index_pc + value + MEM_SIZE)
		% MEM_SIZE, (char *)player->reg[reg]);
	player->carry = true;
	pc_advance(d, player, ret);
	return (0);
}
