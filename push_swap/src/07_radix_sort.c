/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   06_radix_sort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/28 13:02:11 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/11 13:44:32 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/ft_printf.h"
#include "../printf/libft/libft.h"

static void	process_stack(t_stack_node **stack_a, t_stack_node **stack_b,
		int stack_len, int current_bit_position)
{
	int	processed_nbrs;

	processed_nbrs = 0;
	while (processed_nbrs < stack_len)
	{
		if (((*stack_a)->int_index_in_sorted_array >> current_bit_position) & 1)
			ra(stack_a, 0);
		else
			pb(stack_a, stack_b, 0);
		processed_nbrs++;
	}
	while (*stack_b)
		pa(stack_a, stack_b, 0);
}

void	radix_sort(t_stack_node **stack_a,
			t_stack_node **stack_b, int stack_len)
{
	int	current_bit_position;
	int	max_bits;

	if (!stack_a || !*stack_a)
		return (ft_putendl_fd("Error", 2));
	assign_indices(stack_a);
	current_bit_position = 0;
	max_bits = 0;
	while ((1 << max_bits) < stack_len)
		max_bits++;
	while (current_bit_position < max_bits)
	{
		process_stack(stack_a, stack_b, stack_len, current_bit_position);
		current_bit_position++;
	}
}
