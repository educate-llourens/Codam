/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   05_sort_hundred.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lelouren <lelouren@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/15 11:31:14 by lelouren      #+#    #+#                 */
/*   Updated: 2025/10/17 14:25:35 by lelouren      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	assign_chunks(t_stack_node **stack_a, int len);
void	sorting_algorithm(t_stack_node **stack_a, t_stack_node **stack_b,
			int len);

void	sort_hundred(t_stack_node **stack_a, t_stack_node **stack_b, int len)
{
	if (!stack_a || !*stack_a)
		return ;
	assign_indices(stack_a);
	assign_chunks(stack_a, len);
	assign_min(stack_a);
	assign_max(stack_a);
	sorting_algorithm(stack_a, stack_b, len);
}

void	assign_chunks(t_stack_node **stack_a, int len)
{
	t_stack_node	*current_node;

	current_node = *stack_a;
	while (*stack_a)
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
		printf("%d, ", current_node->chunk_nbr);
		if (current_node->ptr_next)
			current_node = current_node->ptr_next;
		else
			break ;
	}
}

void	assign_min(t_stack_node **stack_a)
{
	t_stack_node	*current_node;

	current_node = *stack_a;
	while (*stack_a)
	{
		if (current_node->chunk_nbr == 1)
			current_node->chunk_min = 0;
		else if (current_node->chunk_nbr == 2)
			current_node->chunk_min = 20;
		else if (current_node->chunk_min == 3)
			current_node->chunk_min = 40;
		else if (current_node->chunk_nbr == 4)
			current_node->chunk_min = 60;
		else
			current_node->chunk_min = 80;
		if (current_node->ptr_next)
			current_node = current_node->ptr_next;
	}
}

void	assign_max(t_stack_node **stack_a)
{
	t_stack_node	*current_node;

	current_node = *stack_a;
	while (*stack_a)
	{
		if (current_node->chunk_nbr == 1)
			current_node->chunk_max = 19;
		else if (current_node->chunk_nbr == 2)
			current_node->chunk_max = 39;
		else if (current_node->chunk_min == 3)
			current_node->chunk_max = 59;
		else if (current_node->chunk_nbr == 4)
			current_node->chunk_max = 79;
		else
			current_node->chunk_max = 100;
		if (current_node->ptr_next)
			current_node = current_node->ptr_next;
	}
}

void	sorting_algorithm(t_stack_node **stack_a, t_stack_node **stack_b,
		int len)
{
	int				current_chunk;
	t_stack_node	*current_node;

	current_chunk = 1;
	current_node = *stack_a;
	while (*stack_a)
	{
		if (current_node->chunk_nbr == current_chunk)
		{
			pb(stack_a, stack_b, 0);
			if (current_node->int_index_in_sorted_array - current_node->chunk_min < 10)
				rb(stack_b, 0);
			else
				ra(stack_a, 0);
		}
		current_node = current_node->ptr_next;
	}
}
