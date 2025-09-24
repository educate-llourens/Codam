/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/09 15:19:14 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/10 15:08:57 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Adds the node ’new’ at the end of the list */

void	ft_lstadd_back(t_list **list,
						t_list *new)
{
	t_list	*last_node;

	if (!list || !new)
		return ;
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	last_node = ft_lstlast(*list);
	last_node->next = new;
}
