/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_last_new.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/09 15:13:13 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/09 17:52:23 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*Allocates with malloc and returns a new node.*/
t_list	*ft_lstnew(void *content)
{
	t_list	*pntr_next_node;

	pntr_next_node = malloc(sizeof(t_list));
	if (!pntr_next_node)
		return (0);
	pntr_next_node->content = content;
	pntr_next_node->next = 0;
	return (pntr_next_node);
}
