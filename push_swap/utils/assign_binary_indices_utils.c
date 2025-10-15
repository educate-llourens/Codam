/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   assign_binary_indices_utils.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/24 15:27:57 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/10 21:54:36 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/libft/libft.h"
#include <stdio.h>

int	*linkedlist_to_array(t_stack_node *stack)
{
	int				*array;
	t_stack_node	*current_node;
	int				i;

	i = 0;
	current_node = stack;
	array = malloc(sizeof(int) * stack_len(stack));
	if (!array)
		return (NULL);
	while (current_node)
	{
		array[i] = current_node->int_nbr;
		current_node = current_node->ptr_next;
		i++;
	}
	return (array);
	free(array);
}

int	*sort_array(int *array, int len)
{
	int	first_nbr_index;
	int	second_nbr_index;
	int	temp;

	first_nbr_index = 0;
	while (first_nbr_index < len - 1)
	{
		second_nbr_index = first_nbr_index + 1;
		while (second_nbr_index < len)
		{
			if (array[first_nbr_index] > array[second_nbr_index])
			{
				temp = array[first_nbr_index];
				array[first_nbr_index] = array[second_nbr_index];
				array[second_nbr_index] = temp;
			}
			second_nbr_index++;
		}
		first_nbr_index++;
	}
	return (array);
	free(array);
}
