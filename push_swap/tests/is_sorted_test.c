/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_sorted_test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 09:01:52 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/06 09:34:33 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/libft/libft.h"

int	is_reverse_sorted(t_stack_node *stack)
{
	if (!stack)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	while (stack->ptr_next)
	{
		if (stack->int_nbr < stack->ptr_next->int_nbr)
			return (0);
		stack = stack->ptr_next;
	}
	return (1);
}

int	main(void)
{
	t_stack_node 	*a;
    t_stack_node 	*b;
    t_stack_node 	*c;

	t_stack_node	*d;
	t_stack_node	*e;
	t_stack_node	*f;

	FILE			*fd;
	t_stack_node	*temp;
	int				checker;
	
#pragma region ARRANGE
	a = NULL;
	b = NULL;
	c = NULL;
	
	d = NULL;
	e = NULL;
	f = NULL;

    a = (t_stack_node *)malloc(sizeof(t_stack_node));
    b = (t_stack_node *)malloc(sizeof(t_stack_node));
    c = (t_stack_node *)malloc(sizeof(t_stack_node));

	d = (t_stack_node *)malloc(sizeof(t_stack_node));
    e = (t_stack_node *)malloc(sizeof(t_stack_node));
    f = (t_stack_node *)malloc(sizeof(t_stack_node));
	temp = malloc(sizeof(t_stack_node));
	fd = fopen( "./tests/test_logs.txt", "w" );
	checker = 0;

    if (!a || !b || !c || !d || !e || !f) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    a->ptr_prev = NULL;
    a->int_nbr = 5;
    a->ptr_next = b;

    b->ptr_prev = a;
    b->int_nbr = 3;
    b->ptr_next = c;

    c->ptr_prev = b;
    c->int_nbr = 4;
    c->ptr_next = NULL;

	d->ptr_prev = NULL;
	d->int_nbr = 1;
	d->ptr_next = e;

	e->ptr_prev = d;
	e->int_nbr = 3;
	e->ptr_next = f;

	f->ptr_prev = e;
	f->int_nbr = 4;
	f->ptr_next = NULL;

#pragma endregion

	int result = is_reverse_sorted(a);
	printf("is_reverse_sorted: %d\n", result);

	fclose(fd);
	return (0);
}
