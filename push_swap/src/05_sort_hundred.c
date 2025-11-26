/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   05_sort_hundred.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lelouren <lelouren@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/15 11:31:14 by lelouren      #+#    #+#                 */
/*   Updated: 2025/11/24 09:35:51 by lelouren      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	assign_chunks(t_stack_node **stack_a);
void	sorting_algorithm(t_stack_node **stack_a, t_stack_node **stack_b,
			int len);
void	assign_min(t_stack_node **stack_a);
void	assign_max(t_stack_node **stack_a);

void	sort_hundred(t_stack_node **stack_a, t_stack_node **stack_b, int len)
{
	if (!stack_a || !*stack_a)
		return ;
	assign_indices(stack_a);
	assign_chunks(stack_a);
	assign_min(stack_a);
	assign_max(stack_a);
	sorting_algorithm(stack_a, stack_b, len);
}

void	assign_chunks(t_stack_node **stack_a)
{
	t_stack_node	*current_node;

	current_node = *stack_a;
	while (current_node)
	{
		if (current_node->int_index_in_sorted_array >= 0
			&& current_node->int_index_in_sorted_array <= 19)
			current_node->chunk_nbr = 1;
		else if (current_node->int_index_in_sorted_array >= 20
			&& current_node->int_index_in_sorted_array <= 39)
			current_node->chunk_nbr = 2;
		else if (current_node->int_index_in_sorted_array >= 40
			&& current_node->int_index_in_sorted_array <= 59)
			current_node->chunk_nbr = 3;
		else if (current_node->int_index_in_sorted_array >= 60
			&& current_node->int_index_in_sorted_array <= 79)
			current_node->chunk_nbr = 4;
		else
			current_node->chunk_nbr = 5;
		current_node = current_node->ptr_next;
	}
}

void	assign_min(t_stack_node **stack_a)
{
	t_stack_node	*current_node;

	current_node = *stack_a;
	while (current_node)
	{
		if (current_node->chunk_nbr == 1)
			current_node->chunk_min = 0;
		else if (current_node->chunk_nbr == 2)
			current_node->chunk_min = 20;
		else if (current_node->chunk_nbr == 3)
			current_node->chunk_min = 40;
		else if (current_node->chunk_nbr == 4)
			current_node->chunk_min = 60;
		else
			current_node->chunk_min = 80;
		current_node = current_node->ptr_next;
	}
}

void	assign_max(t_stack_node **stack_a)
{
	t_stack_node	*current_node;

	current_node = *stack_a;
	while (current_node)
	{
		if (current_node->chunk_nbr == 1)
			current_node->chunk_max = 19;
		else if (current_node->chunk_nbr == 2)
			current_node->chunk_max = 39;
		else if (current_node->chunk_nbr == 3)
			current_node->chunk_max = 59;
		else if (current_node->chunk_nbr == 4)
			current_node->chunk_max = 79;
		else
			current_node->chunk_max = 100;
		current_node = current_node->ptr_next;
	}
}

void	sorting_algorithm(t_stack_node **stack_a, t_stack_node **stack_b,
		int len)
{
	int				current_chunk;
	t_stack_node	*current_node;

	current_chunk = 5;
	while (current_chunk >= 0)
	{
		chunk_to_b(stack_a, stack_b, current_chunk);
		current_node = *stack_b;
		while (stack_len(*stack_b) > 0)
			move_largest_to_a(stack_a, stack_b, &len);
		current_chunk--;
	}
}
