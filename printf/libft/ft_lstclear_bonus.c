/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/09 16:01:28 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/10 15:25:57 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
	Deletes and frees the given node and every successor of that node, 
	using the function ’del’and free. Finally, the pointer to the 
	list must be set to NULL.
*/

void	ft_lstclear(t_list **list,
					void (*del)(void*))
{
	t_list	*temp;

	if (!list || !del)
		return ;
	while (*list)
	{
		temp = (*list)->next;
		ft_lstdelone(*list, del);
		*list = temp;
	}
}
