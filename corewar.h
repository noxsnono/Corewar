/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 15:38:50 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/06 15:38:51 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft/includes/libft.h"

typedef struct s_asm
{
	char	*name;

}t_asm

t_asm	*getASMdata( void );
int		sti(void)

#endif
