/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_tests.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 10:45:38 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/07 15:21:34 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/ft_printf.h"
#include <stdio.h>

static void	log_tick(void)
{
	printf("\033[0;32m ✔ \033[0;37m \n");
}

static void	log_error(char *message)
{
	printf("\033[0;31m%s\n\n\033[0;37m", message);
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
    b->int_nbr = 7;
    b->ptr_next = c;

    c->ptr_prev = b;
    c->int_nbr = 8;
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


	fprintf(fd, "Stack a: \n");
	temp = a;
	while (temp)
	{
		fprintf(fd, "%d\n", temp->int_nbr);
		temp = temp->ptr_next;
	}
	
	fprintf(fd, "Stack b: \n");
	temp = d;
	while (temp)
	{
		fprintf(fd, "%d\n", temp->int_nbr);
		temp = temp->ptr_next;
	}
	fprintf(fd, "\n");

#pragma endregion

#pragma region SWAP
	sa(&a, checker);
	fprintf(fd, "Result of sa:\n");
	temp = a;
	while (temp)
	{
		fprintf(fd, "%d\n", temp->int_nbr);
		temp = temp->ptr_next;
	}
	if (a->int_nbr == 7 && a->ptr_next->int_nbr == 5 && a->ptr_next->ptr_next->int_nbr == 8)
		log_tick();
	else 
		log_error("sa failure");
	fprintf(fd, "\n");

	sb(&d, checker);
	fprintf(fd, "Result of sb:\n");
	temp = d;
	while (temp)
	{
		fprintf(fd, "%d\n", temp->int_nbr);
		temp = temp->ptr_next;
	}
	if (d->int_nbr == 3 && d->ptr_next->int_nbr == 1 && d->ptr_next->ptr_next->int_nbr == 4)
		log_tick();
	else 
		log_error("sb failure");
	fprintf(fd, "\n");

	ss(&a, &d, checker);
	fprintf(fd, "Result of ss:\n");
	fprintf(fd, "Stack a:\n");
	temp = a;
	while (temp)
	{
		fprintf(fd, "%d\n", temp->int_nbr);
		temp = temp->ptr_next;
	}

	fprintf(fd, "Stack b:\n");
	temp = d;
	while (temp)
	{
		fprintf(fd, "%d\n", temp->int_nbr);
		temp = temp->ptr_next;
	}

	if ((a->int_nbr == 5 && a->ptr_next->int_nbr == 7 && a->ptr_next->ptr_next->int_nbr == 8)
		&& (d->int_nbr == 1 && d->ptr_next->int_nbr == 3 && d->ptr_next->ptr_next->int_nbr == 4))
		log_tick();
	else 
		log_error("sa failure");
	fprintf(fd, "\n");

#pragma endregion

#pragma region ROTATE
	ra(&a, checker);
	fprintf(fd, "Result of ra:\n");
	temp = a;
	while (temp)
	{
		fprintf(fd, "%d\n", temp->int_nbr);
		temp = temp->ptr_next;
	}
	if (a->int_nbr == 7 && a->ptr_next->int_nbr == 8 && a->ptr_next->ptr_next->int_nbr == 5)
		log_tick();
	else 
		log_error("\033[0;31mra failure\033[0;37m");
	fprintf(fd, "\n");

	rb(&d, checker);
	fprintf(fd, "Result of sb:\n");
	temp = d;
	while (temp)
	{
		fprintf(fd, "%d\n", temp->int_nbr);
		temp = temp->ptr_next;
	}
	if (d->int_nbr == 3 && d->ptr_next->int_nbr == 4 && d->ptr_next->ptr_next->int_nbr == 1)
		log_tick();
	else 
		log_error("rb failure");
	fprintf(fd, "\n");

	rr(&a, &d, checker);
	fprintf(fd, "Result of rr:\n");
	fprintf(fd, "Stack a:\n");
	temp = a;
	while (temp)
	{
		fprintf(fd, "%d\n", temp->int_nbr);
		temp = temp->ptr_next;
	}

	fprintf(fd, "Stack b:\n");
	temp = d;
	while (temp)
	{
		fprintf(fd, "%d\n", temp->int_nbr);
		temp = temp->ptr_next;
	}

	if ((a->int_nbr == 8 && a->ptr_next->int_nbr == 5 && a->ptr_next->ptr_next->int_nbr == 7)
		&& (d->int_nbr == 4 && d->ptr_next->int_nbr == 1 && d->ptr_next->ptr_next->int_nbr == 3))
		log_tick();
	else 
		log_error("rr failure");
	fprintf(fd, "\n");
#pragma endregion

#pragma region REVERSE ROTATE
	rra(&a, checker);
	fprintf(fd, "Result of rra:\n");
	temp = a;
	while (temp)
	{
		fprintf(fd, "%d\n", temp->int_nbr);
		temp = temp->ptr_next;
	}
	if (a->int_nbr == 7 && a->ptr_next->int_nbr == 8 && a->ptr_next->ptr_next->int_nbr == 5)
		log_tick();
	else 
		log_error("\033[0;31mrra failure\033[0;37m");
	fprintf(fd, "\n");

	rrb(&d, checker);
	fprintf(fd, "Result of rrb:\n");
	temp = d;
	while (temp)
	{
		fprintf(fd, "%d\n", temp->int_nbr);
		temp = temp->ptr_next;
	}
	if (d->int_nbr == 3 && d->ptr_next->int_nbr == 4 && d->ptr_next->ptr_next->int_nbr == 1)
		log_tick();
	else 
		log_error("rrb failure");
	fprintf(fd, "\n");

	rrr(&a, &d, checker);
	fprintf(fd, "Result of rrr:\n");
	fprintf(fd, "Stack a:\n");
	temp = a;
	while (temp)
	{
		fprintf(fd, "%d\n", temp->int_nbr);
		temp = temp->ptr_next;
	}

	fprintf(fd, "Stack b:\n");
	temp = d;
	while (temp)
	{
		fprintf(fd, "%d\n", temp->int_nbr);
		temp = temp->ptr_next;
	}

	if ((a->int_nbr == 5 && a->ptr_next->int_nbr == 7 && a->ptr_next->ptr_next->int_nbr == 8)
		&& (d->int_nbr == 1 && d->ptr_next->int_nbr == 3 && d->ptr_next->ptr_next->int_nbr == 4))
		log_tick();
	else 
		log_error("rrr failure");
	fprintf(fd, "\n");

#pragma endregion

#pragma region PUSH
	pa(&a, &d, checker);
	fprintf(fd, "Result of push a:\n");
	//print stack a
	fprintf(fd, " stack_a:\n");
	temp = a;
	while (temp)
	{
		fprintf(fd, "%d\n", temp->int_nbr);
		temp = temp->ptr_next;
	}
	fprintf(fd, "\n");
	//print stack b
	fprintf(fd, " stack_b:\n");
	temp = d;
	while (temp)
	{
		fprintf(fd, "%d\n", temp->int_nbr);
		temp = temp->ptr_next;
	}

	if ((a->int_nbr == 1 && a->ptr_next->int_nbr == 5 && a->ptr_next->ptr_next->int_nbr == 7 && a->ptr_next->ptr_next->ptr_next->int_nbr == 8)
		&& d->int_nbr == 3 && d->ptr_next->int_nbr == 4)
		log_tick();
	else 
		log_error("\033[0;31mpa failure\033[0;37m");
	fprintf(fd, "\n");

	pb(&a, &d, checker);
	fprintf(fd, "Result of push b:\n");
	//print stack a
	fprintf(fd, " stack_a:\n");
	temp = a;
	while (temp)
	{
		fprintf(fd, "%d\n", temp->int_nbr);
		temp = temp->ptr_next;
	}
	fprintf(fd, "\n");
	//print stack b
	fprintf(fd, " stack_b:\n");
	temp = d;
	while (temp)
	{
		fprintf(fd, "%d\n", temp->int_nbr);
		temp = temp->ptr_next;
	}

	if ((a->int_nbr == 5 && a->ptr_next->int_nbr == 7 && a->ptr_next->ptr_next->int_nbr == 8)
		&& d->int_nbr == 1 && d->ptr_next->int_nbr == 3 && d->ptr_next->ptr_next->int_nbr == 4)
		log_tick();
	else 
		log_error("\033[0;31mpb failure\033[0;37m");
	fprintf(fd, "\n");
#pragma endregion

	while (a)
	{
		temp = a;
		a = a->ptr_next;
		free(temp);
	}
	fclose(fd);
	return (0);
}
