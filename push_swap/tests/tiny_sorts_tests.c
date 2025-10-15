/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tiny_sorts_tests.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/23 14:45:01 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/24 13:31:24 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/libft/libft.h"
#include <stdio.h>

void	free_split(char **split)
{
    int	i;

    i = 0;
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
	int				len;
	t_stack_node	*temp;
	FILE			*fd;
	char			**split_argv;

	fd = fopen("./tests/test_logs.txt", "w");
	if (fd == NULL)
	{
		printf("Error opening file");
		return (0);
	}
	a_node = NULL;
	split_argv = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (printf("issue with argc check"), 1);
	else if (argc == 2)
		split_argv = ft_split(argv[1], ' ');
	else
		split_argv = argv + 1;
	init_stack(&a_node, split_argv);

	fprintf(fd, "Stack before swap: \n");
	temp = a_node;
	while (temp)
	{
		fprintf(fd, "%d\n", temp->int_nbr);
		temp = temp->ptr_next;
	}

	if (is_sorted(a_node) == 0)
	{		
		len = stack_len(a_node);
		if (len == 2)
			sa(&a_node, false);
		else if (len == 3)
			sort_three_nbr(&a_node);
		else
		{
			printf("stack too large");
			return (0);
		}
	}

	fprintf(fd, "\n");
	fprintf(fd, "Stack after swap: \n");
	temp = a_node;
	while (temp)
	{
		fprintf(fd, "%d\n", temp->int_nbr);
		temp = temp->ptr_next;
	}
	
	if (a_node && a_node->ptr_next && a_node->ptr_next->ptr_next &&
		a_node->int_nbr == 1 && a_node->ptr_next->int_nbr == 3 && a_node->ptr_next->ptr_next->int_nbr == 5)
		log_tick();
	else
		log_error("Error: stack not sorted correctly");

	if (argc == 2 && split_argv)
	{
		free_split(split_argv);
		split_argv = NULL;
	}
	free_stack(&a_node);
	return (0);
}