/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate_operations.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 12:34:44 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/10 14:34:20 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/ft_printf.h"
#include "../printf/libft/libft.h"

static void	reverse_rotate(t_stack_node **head)
{
	t_stack_node	*first_node;
	t_stack_node	*last_node;

	if (!head || !(*head) || !(*head)->ptr_next)
	{
		ft_putendl_fd("Error", 2);
		return ;
	}
	first_node = *head;
	last_node = ft_lstlast(*head);
	last_node->ptr_next = first_node;
	last_node->ptr_prev->ptr_next = NULL;
	last_node->ptr_prev = NULL;
	first_node->ptr_prev = last_node;
	*head = last_node;
}

void	rra(t_stack_node **stack_a, int checker)
{
	reverse_rotate(stack_a);
	if (checker == 1 || 1)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **stack_b, int checker)
{
	reverse_rotate(stack_b);
	if (checker == 1 || 1)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b, int checker)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (checker == 1 || 1)
		ft_printf("rrr\n");
}
