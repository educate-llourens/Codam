/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_hundred_utils.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lelouren <lelouren@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/15 12:35:46 by lelouren      #+#    #+#                 */
/*   Updated: 2025/10/21 15:47:37 by lelouren      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "libft/libft.h"

t_stack_node	*find_largest(t_stack_node *stack)
{
	int				largest_nbr;
	t_stack_node	*largest_node;

	if (!stack)
	{
		ft_putendl_fd("Error", 2);
		return (NULL);
	}
	largest_node = NULL;
	largest_nbr = INT_MIN;
	largest_nbr = stack->int_nbr;
	largest_node = stack;
	while (stack)
	{
		if (stack->int_nbr > largest_nbr)
		{
			largest_nbr = stack->int_nbr;
			largest_node = stack;
		}
		stack = stack->ptr_next;
	}
	return (largest_node);
}
