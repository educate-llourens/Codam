/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/09 13:53:50 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/10 13:38:40 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Adds the node ’new’ at the beginning of the list. */

void	ft_lstadd_front(t_list **list,
						t_list *new)
{
	new->next = *list;
	*list = new;
}
