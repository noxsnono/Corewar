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

typedef struct s_cmd
{
	char	*line;
	t_cmd	*next;
}t_cmd

typedef struct s_asm
{
	char	*name;

}t_asm

t_asm	*getASMdata( void );

t_cmp	*s_lstCreate(char *string);
void	s_lstFreeLink(t_cmd *toDel);
void	s_lstAddEnd(t_cmd **lst, t_cmd *new);
void	s_lstDelAll(t_cmd **lst, );

int		s_sti(void);

#endif