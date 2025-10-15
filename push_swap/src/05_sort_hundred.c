/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   05_sort_hundred.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lelouren <lelouren@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/15 11:31:14 by lelouren      #+#    #+#                 */
/*   Updated: 2025/10/15 12:40:37 by lelouren      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	assign_chunks(t_stack_node **stack_a, int len);

void	sort_hundred(t_stack_node **stack_a, t_stack_node **stack_b, int len)
{
	int	*array;
	int	*sorted_array;

	if (!stack_a || !*stack_a)
		return (ft_putendl_fd("Error", 2));
	assign_indices(stack_a);
	assign_chunks(stack_a, len);

}

void	assign_chunks(t_stack_node **stack_a, int len)
{
	int				*array;
	int				*sorted_array;
	int				total_chunks;

	array = linkedlist_to_array(*stack_a);
	sorted_array = sort_array(array, len);
	find_chunks(sorted_array);
	
	
}
