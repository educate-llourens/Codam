/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/09 14:19:58 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/10 13:42:40 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Counts the number of nodes in a list */

int	ft_lstsize(t_list *list)
{
	int	size_list;

	size_list = 0;
	while (list)
	{
		list = list->next;
		size_list++;
	}
	return (size_list);
}
