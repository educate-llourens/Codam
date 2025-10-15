/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 17:21:33 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/11 20:49:00 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/ft_printf.h"
#include "../printf/libft/libft.h"

void	free_and_handle(t_stack_node **stack_a_node)
{
	free_stack(stack_a_node);
	ft_putendl_fd("Error", 2);
	exit (1);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp_node;
	t_stack_node	*current_node;

	if (!stack)
	{
		ft_putendl_fd("Error", 2);
		return ;
	}
	current_node = *stack;
	while (current_node)
	{
		temp_node = current_node->ptr_next;
		current_node->int_nbr = 0;
		free(current_node);
		current_node = temp_node;
	}
	*stack = NULL;
}
