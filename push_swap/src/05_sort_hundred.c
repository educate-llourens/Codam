/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   05_sort_hundred.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lelouren <lelouren@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/15 11:31:14 by lelouren      #+#    #+#                 */
/*   Updated: 2025/10/23 10:02:22 by lelouren      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	assign_chunks(t_stack_node **stack_a);
void	sorting_algorithm(t_stack_node **stack_a, t_stack_node **stack_b,
			int len);
void	move_smallest_to_a(t_stack_node **stack_a, t_stack_node **stack_b,
			int *len);
void	chunk_to_b(t_stack_node **stack_a, t_stack_node **stack_b,
			int current_chunk);
void	assign_min(t_stack_node **stack_a);
void	assign_max(t_stack_node **stack_a);
void	move_largest_to_a(t_stack_node **stack_a, t_stack_node **stack_b,
			int *len);
int		chunk_in_a(t_stack_node **stack_a, int current_chunk);
int	index_of_node(t_stack_node **stack, t_stack_node *target);

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
	int				processed_nbrs;

	current_chunk = 5;
	while (current_chunk >= 0)
	{
		chunk_to_b(stack_a, stack_b, current_chunk);
		current_node = *stack_b;
		processed_nbrs = 0;
		while (stack_len(*stack_b) > 0)
			move_largest_to_a(stack_a, stack_b, &len);
		current_chunk--;
	}
}

void	move_largest_to_a(t_stack_node **stack_a, t_stack_node **stack_b,
		int *len)
{
	while (*len > 0 && find_largest(*stack_b))
	{
		if (stack_len(*stack_b) == 1)
		{
			pa(stack_a, stack_b, 1);
			len--;
			break ;
		}
		else if ((find_largest(*stack_b) == ft_lstlast(*stack_b))
			&& stack_len(*stack_b) > 1)
		{
			rrb(stack_b, 1);
			pa(stack_a, stack_b, 1);
			(*len)--;
		}
		else if (find_largest(*stack_b) == (*stack_b))
		{
			pa(stack_a, stack_b, 1);
			(*len)--;
		}
		else if (stack_len(*stack_b) > 0)
			rb(stack_b, 1);
	}
}

void	chunk_to_b(t_stack_node **stack_a, t_stack_node **stack_b,
		int current_chunk)
{
	t_stack_node	*current_node;
	int				largest_index;
	int				b_len;

	current_node = *stack_a;
	while (chunk_in_a(stack_a, current_chunk))
	{
		if ((*stack_a)->chunk_nbr == current_chunk)
		{
			pb(stack_a, stack_b, 1);
			b_len = stack_len(*stack_b);
			largest_index = index_of_node(stack_b, find_largest(*stack_b));
			if (largest_index <= (b_len / 2) && stack_len(*stack_b) > 1)
				rb(stack_b, 1);
			else if (b_len > 1)
				rrb(stack_b, 1);
		}
		else
			ra(stack_a, 1);
	}
}

int	index_of_node(t_stack_node **stack, t_stack_node *target)
{
	int				index;
	t_stack_node	*current;

	index = 0;
	current = *stack;
	while (current)
	{
		if (current == target)
			return (index);
		current = current->ptr_next;
		index++;
	}
	return (-1); // target node not found in stack
}

int	chunk_in_a(t_stack_node **stack_a, int current_chunk)
{
	t_stack_node	*current_node;

	current_node = *stack_a;
	while (current_node)
	{
		if (current_node->chunk_nbr == current_chunk)
			return (1);
		current_node = current_node->ptr_next;
	}
	return (0);
}
