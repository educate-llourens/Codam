/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_hundred_utils.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lelouren <lelouren@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/15 12:35:46 by lelouren      #+#    #+#                 */
/*   Updated: 2025/10/23 10:33:48 by lelouren      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "libft/libft.h"

void			chunk_to_b(t_stack_node **stack_a, t_stack_node **stack_b,
					int current_chunk);
void			move_largest_to_a(t_stack_node **stack_a,
					t_stack_node **stack_b, int *len);
int				chunk_in_a(t_stack_node **stack_a, int current_chunk);
int				index_of_node(t_stack_node **stack, t_stack_node *target);

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
	return (-1);
}
