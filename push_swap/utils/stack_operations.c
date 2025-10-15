/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_operations.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/16 10:02:21 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/29 15:52:17 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/libft/libft.h"
#include "../printf/ft_printf.h"

static void	swap(t_stack_node **head)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_stack_node	*c;

	if (!head || !(*head) || !(*head)->ptr_next)
	{
		ft_putendl_fd("Error", 2);
		return ;
	}
	a = *head;
	b = (*head)->ptr_next;
	c = (*head)->ptr_next->ptr_next;
	*head = b;
	b->ptr_next = a;
	b->ptr_prev = NULL;
	a->ptr_next = c;
	a->ptr_prev = b;
	if (c != NULL)
		c->ptr_prev = a;
}

void	sa(t_stack_node **stack_a, int checker)
{
	swap(stack_a);
	if (checker == 1 || 1)
		ft_printf("sa\n");
}

void	sb(t_stack_node **stack_b, int checker)
{
	swap(stack_b);
	if (checker == 1 || 1)
		ft_printf("sb\n");
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b, int checker)
{
	swap(stack_a);
	swap(stack_b);
	if (checker == 1 || 1)
		ft_printf("ss\n");
}
