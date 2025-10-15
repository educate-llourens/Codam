/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/10 21:58:36 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/27 17:08:04 by llourens      ########   odam.nl         */
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

int	main(int argc, char **argv)
{
	t_stack_node	*a_node;
	t_stack_node	*b_node;
	t_stack_node	*temp;
	char			**split_argv;
	int				len;
	FILE			*fd;

	# pragma region Error handling
		a_node = NULL;
		b_node = NULL;
		if (argc == 1 || (argc == 2 && !argv[1][0]))
			return (printf("issue with argc check"), 1);
		else if (argc == 2)
			split_argv = ft_split(argv[1], ' ');
		else
			split_argv = argv + 1;
	# pragma endregion
		
	# pragma region arrange	and act
		fd = fopen( "./tests/test_logs.txt", "w" );
		init_stack(&a_node, split_argv);
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
	# pragma endregion

	#pragma region test
	temp = a_node;
	while (temp)
	{
		fprintf(fd, "%d\n", temp->int_nbr);
		temp = temp->ptr_next;
	}

	#pragma endregion

		free_stack(&a_node);
		// free_split(argv);
		fclose(fd);
		return (0);
}
