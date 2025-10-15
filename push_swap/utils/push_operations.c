/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_operations.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 14:35:05 by llourens      #+#    #+#                 */
/*   Updated: 2025/03/05 18:21:15 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/ft_printf.h"
#include "../printf/libft/libft.h"

static void	push(t_stack_node **head, t_stack_node **dest)
{
	t_stack_node	*src_a;
	t_stack_node	*src_b;
	t_stack_node	*dest_a;

	if (!head || !(*head))
		return (ft_putendl_fd("Error", 2));
	src_a = *head;
	src_b = (*head)->ptr_next;
	dest_a = *dest;
	*head = src_b;
	if (src_b)
		src_b->ptr_prev = NULL;
	src_a->ptr_prev = NULL;
	if (!(*dest))
	{
		*dest = src_a;
		src_a->ptr_next = NULL;
	}
	else
	{
		src_a->ptr_next = dest_a;
		dest_a->ptr_prev = src_a;
		*dest = src_a;
	}
}

void	pa(t_stack_node **stack_a, t_stack_node **stack_b, int checker)
{
	push(stack_b, stack_a);
	if (checker == 1 || 1)
		ft_printf("pa\n");
}

void	pb(t_stack_node **stack_a, t_stack_node **stack_b, int checker)
{
	push(stack_a, stack_b);
	if (checker == 1 || 1)
		ft_printf("pb\n");
}
