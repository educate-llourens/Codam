/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   binary_indices_tests.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/27 12:15:26 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/27 14:55:07 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/libft/libft.h"
#include <stdio.h>

void free_split(char **split)
{
    int i = 0;

    if (!split)
        return;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

static void	log_tick(void)
{
	printf("\033[0;32m ✔ \033[0;37m \n");
}

static void	log_error(char *message)
{
	printf("\033[0;31m%s\033[0;37m", message);
}

int	main (void)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_stack_node	*c;
	t_stack_node	*temp_stack;
	t_stack_node	*stack_indice_index;
	int				*array;
	int				array_len;
	int				*sorted_array;
	int				*temp;
	int				i;	
	FILE			*fd;

	#pragma region assign
		fd = fopen( "./tests/test_logs.txt", "w" );
		a = malloc(sizeof(t_stack_node));
		b = malloc(sizeof(t_stack_node));
		c = malloc(sizeof(t_stack_node));

		a->ptr_prev = NULL;
		a->int_nbr = 1;
		a->ptr_next = b;

		b->ptr_prev = a;
		b->int_nbr = 5;
		b->ptr_next = c;

		c->ptr_prev = b;
		c->int_nbr = 3;
		c->ptr_next = NULL;

		array_len = stack_len(a);
	#pragma endregion

	#pragma region linkedlist_to_array
		array = linkedlist_to_array(a);
		fprintf(fd, "linkedlist_to_array:\n");
		printf("linkedlist_to_array: ");
		temp = array;
		i = 0;
		while (temp[i])
		{
			fprintf(fd, "%d\n", temp[i]);
			i++;
		}
		if (a->int_nbr == 1 && b->int_nbr == 5 && c->int_nbr == 3)
			log_tick();
		else
			log_error("Error: linkedlist_to_array failed\n");
	#pragma endregion

	#pragma region sort_array
	sorted_array = sort_array(array, array_len);
	fprintf(fd, "sorted_array:\n");
	printf("sorted_array: ");
	i = 0;
	temp = sorted_array;
	while (temp[i])
	{
		fprintf(fd, "%d\n", temp[i]);
		i++;
	}
	if (sorted_array[0] == 1 && sorted_array[1] == 3 && sorted_array[2] == 5)
		log_tick();
	else
		log_error("Error: sort_array failed\n");
	#pragma endregion

	#pragma region assign_indices
	assign_indices(&a);
	fprintf(fd, "assign_indices:\n");
	printf("assign_indices: ");
	temp_stack = a;
	while (temp_stack)
	{
		fprintf(fd, "%d\n", temp_stack->int_index_in_sorted_array);
		temp_stack = temp_stack->ptr_next;
	}
	if (a->int_index_in_sorted_array == 0 && b->int_index_in_sorted_array == 2 && c->int_index_in_sorted_array == 1)
		log_tick();
	else
		log_error("Error: assign_indices failed\n");
	#pragma endregion

		fclose(fd);
		free_stack(&a);
		return (0);
}