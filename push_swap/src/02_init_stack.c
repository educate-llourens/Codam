/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   02_init_stack.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 16:55:16 by llourens      #+#    #+#                 */
/*   Updated: 2025/11/27 08:50:08 by lelouren      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/ft_printf.h"
#include "../printf/libft/libft.h"

void	init_error_handle(t_stack_node **node, char **list, int argc)
{
	if (argc == 2)
		free_split(list);
	free_and_handle(node);
}

void	init_stack(t_stack_node **stack_a_node, char **argv_list, int argc)
{
	int		i;
	long	long_nbr;

	i = 0;
	long_nbr = (long) NULL;
	while (argv_list[i])
	{
		if (is_syntax_error(argv_list[i]) == 1)
			init_error_handle(stack_a_node, argv_list, argc);
		long_nbr = ft_atol(argv_list[i]);
		if (long_nbr < INT_MIN || long_nbr > INT_MAX)
			init_error_handle(stack_a_node, argv_list, argc);
		if (is_duplicate(*stack_a_node, long_nbr) == 1)
			init_error_handle(stack_a_node, argv_list, argc);
		append_node(stack_a_node, long_nbr);
		i++;
	}
}

void	append_node(t_stack_node **stack_a, long long_nbr)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (!stack_a)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->ptr_next = NULL;
	new_node->int_nbr = long_nbr;
	if (!*stack_a)
	{
		*stack_a = new_node;
		new_node->ptr_prev = NULL;
	}
	else
	{
		last_node = ft_lstlast(*stack_a);
		last_node->ptr_next = new_node;
		new_node->ptr_prev = last_node;
	}
}
