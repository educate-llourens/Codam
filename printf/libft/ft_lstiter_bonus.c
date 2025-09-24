/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/10 12:59:56 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/10 15:28:48 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
	Iterates the list ’list’ and applies the function on the 
	content of each node.
*/

void	ft_lstiter(t_list *list,
					void (*function)(void *))
{
	if (!list || !function)
		return ;
	while (list)
	{
		function(list->content);
		list = list->next;
	}
}
