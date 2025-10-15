/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   05_assign_binary_indices.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/24 14:42:58 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/11 14:29:28 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	assign_indices(t_stack_node **stack)
{
	int				*array;
	int				*sorted_array;
	int				array_len;
	int				i;
	t_stack_node	*current_node;

	array = linkedlist_to_array(*stack);
	array_len = stack_len(*stack);
	sorted_array = sort_array(array, array_len);
	current_node = *stack;
	while (current_node)
	{
		i = 0;
		while (i < array_len)
		{
			if (current_node->int_nbr == sorted_array[i])
			{
				current_node->int_index_in_sorted_array = i;
				break ;
			}
			i++;
		}
		current_node = current_node->ptr_next;
	}
	free(array);
}
