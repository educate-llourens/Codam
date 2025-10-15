/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort_tests.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/27 16:24:32 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/27 16:47:56 by llourens      ########   odam.nl         */
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
	printf("\033[0;31m%s\n\n\033[0;37m", message);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a_node;
	t_stack_node	*b_node;
	t_stack_node	*temp;
	char			**split_argv;
	int				len;
	FILE			*fd;

	#pragma region assign
		a_node = NULL;
		b_node = NULL;
		fd = fopen( "./tests/test_logs.txt", "w" );
		if (argc == 1 || (argc == 2 && !argv[1][0]))
			return (printf("issue with argc check"), 1);
		else if (argc == 2)
			split_argv = ft_split(argv[1], ' ');
		init_stack(&a_node, split_argv);
	#pragma endregion

	#pragma region sort
		fprintf(fd, "stack before sort:\n");
		printf("stack before sort:\n");
		temp = a_node;
		while (temp)
		{
			fprintf(fd, "%d\n", temp->int_nbr);
			temp = temp->ptr_next;
		}

		if (!is_sorted(a_node))
		{
			len = stack_len(a_node);
			if (len == 2)
				sa(&a_node, false);
			else if (len == 3)
				sort_three_nbr(&a_node);
			else
				radix_sort(&a_node, &b_node, len);
		}

		fprintf(fd, "stack after sort:\n");
		temp = a_node;
		while (temp)
		{
			fprintf(fd, "%d\n", temp->int_nbr);
			temp = temp->ptr_next;
		}
		if (a_node->int_nbr == 1 && a_node->ptr_next->int_nbr == 3 && a_node->ptr_next->ptr_next->int_nbr == 5)
			log_tick();
		else
		if (argc == 2)
			free_split(split_argv);
	#pragma endregion
		free_stack(&a_node);
		free_split(&split_argv);
		fclose(fd);
		return (0);
}