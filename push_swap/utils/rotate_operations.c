/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_operations.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 10:22:28 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/19 15:15:56 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/libft/libft.h"
#include "../printf/ft_printf.h"

static void	rotate(t_stack_node **head)
{
	t_stack_node	*first_node;
	t_stack_node	*second_node;
	t_stack_node	*last_node;
	if (!head || !(*head) || !(*head)->ptr_next)
	{
		ft_putendl_fd("Error", 2);
		return ;
	}
	first_node = *head;
	second_node = (*head)->ptr_next;
	last_node = ft_lstlast(*head);
	*head = second_node;
	second_node->ptr_prev = NULL;
	first_node->ptr_prev = last_node;
	first_node->ptr_next = NULL;
	last_node->ptr_next = first_node;
}

void	ra(t_stack_node **stack_a, int checker)
{
	rotate(stack_a);
	if (checker == 1 || 1)
		ft_printf("ra\n");
}

void	rb(t_stack_node **stack_b, int checker)
{
	rotate(stack_b);
	if (checker == 1 || 1)
		ft_printf("rb\n");
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b, int checker)
{
	rotate(stack_a);
	rotate(stack_b);
	if (checker == 1 || 1)
		ft_printf("rr\n");
}
