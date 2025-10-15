/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_smallsort_utils.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/23 14:40:38 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/04 09:32:39 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/ft_printf.h"
#include "../printf/libft/libft.h"

t_stack_node	*find_highest(t_stack_node *stack)
{
	int				highest_nbr;
	t_stack_node	*highest_node;

	if (!stack)
	{
		ft_putendl_fd("Error", 2);
		return (NULL);
	}
	highest_node = NULL;
	highest_nbr = INT_MIN;
	highest_nbr = stack->int_nbr;
	highest_node = stack;
	while (stack)
	{
		if (stack->int_nbr > highest_nbr)
		{
			highest_nbr = stack->int_nbr;
			highest_node = stack;
		}
		stack = stack->ptr_next;
	}
	return (highest_node);
}

t_stack_node	*find_smallest(t_stack_node *stack)
{
	int				smallest_nbr;
	t_stack_node	*smallest_node;

	if (!stack)
	{
		ft_putendl_fd("Error", 2);
		return (NULL);
	}
	smallest_node = NULL;
	smallest_nbr = INT_MAX;
	smallest_nbr = stack->int_nbr;
	smallest_node = stack;
	while (stack)
	{
		if (stack->int_nbr < smallest_nbr)
		{
			smallest_nbr = stack->int_nbr;
			smallest_node = stack;
		}
		stack = stack->ptr_next;
	}
	return (smallest_node);
}
