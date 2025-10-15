/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   04_sort_five.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/04 08:58:57 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/12 19:42:49 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	move_smallest_to_b(t_stack_node **stack_a,
			t_stack_node **stack_b, int *len)
{
	t_stack_node	*smallest;

	smallest = find_smallest(*stack_a);
	while (*len > 3 && smallest)
	{
		if (smallest == ft_lstlast(*stack_a))
		{
			rra(stack_a, 1);
			pb(stack_a, stack_b, 1);
			(*len)--;
		}
		else if (smallest == (*stack_a))
		{
			pb(stack_a, stack_b, 1);
			(*len)--;
		}
		else
		{
			ra(stack_a, 1);
		}
		smallest = find_smallest(*stack_a);
	}
}

void	sort_five(t_stack_node **stack_a, t_stack_node **stack_b, int len)
{
	move_smallest_to_b(stack_a, stack_b, &len);
	sort_three_nbr(stack_a);
	pa(stack_a, stack_b, 1);
	if (stack_len(*stack_b) > 0)
		pa(stack_a, stack_b, 1);
}
