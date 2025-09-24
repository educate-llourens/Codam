/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/09 15:40:44 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/10 15:12:01 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Takes as a parameter a node and frees the memory of the node’s content 
	using the function ’del’ given as a parameter and free the node. The 
	memory of’next’ must not be freed.
*/

void	ft_lstdelone(t_list *list,
					void (*del)(void*))
{
	del(list->content);
	free(list);
}
