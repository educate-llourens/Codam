/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/10 21:58:36 by llourens      #+#    #+#                 */
/*   Updated: 2025/11/26 12:56:52 by lelouren      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/ft_printf.h"
#include "../printf/libft/libft.h"
#include "includes/push_swap.h"

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

void	handle_single_argument(char **argv, char ***split_argv)
{
	*split_argv = ft_split(argv[1], ' ');
	if (!*split_argv || !**split_argv || (!ft_isdigit(***split_argv)
			&& ((***split_argv) != '-' || !ft_isdigit((*split_argv)[0][1])))
		|| (ft_strlen((*split_argv)[0]) == 1 && (*split_argv)[0][0] == '-'))
	{
		ft_putendl_fd("Error", 2);
		free_split(*split_argv);
		exit(1);
	}
}

void	handle_sorted_case(t_stack_node **a_node, t_stack_node **b_node,
		int len)
{
	int	len_a;
	int	len_og;

	len_a = len;
	len_og = len;
	if (len_a > 5 && is_reverse_sorted(*a_node))
	{
		while (len_a-- > 0)
			pb(a_node, b_node, 1);
		len_a = len_og;
		while (len_a-- > 1)
		{
			rrb(b_node, 1);
			pa(a_node, b_node, 1);
		}
		pa(a_node, b_node, 1);
	}
}

void	sort_stack(t_stack_node **a_node, t_stack_node **b_node, int len)
{
	if (len == 2)
		sa(a_node, 1);
	else if (len == 3)
		sort_three_nbr(a_node);
	else if (len > 3 && len <= 5)
		sort_five(a_node, b_node, len);
	else if (len > 5 && len <= 100)
		sort_hundred(a_node, b_node, len);
	else
		radix_sort(a_node, b_node, len);
}

/*
	- Takes in a list of nmbers. This can be seperated by spaces or in a
	single string separated by spaces.
	- Delegates the input check, stack initiation, reverse sorted stack
	handling, and sorting.
	- Cleans up at the end, freeing the stacks.
*/

int	main(int argc, char **argv)
{
	t_stack_node	*a_node;
	t_stack_node	*b_node;
	char			**split_argv;
	int				len;

	a_node = NULL;
	b_node = NULL;
	len = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
		handle_single_argument(argv, &split_argv);
	else
		split_argv = argv + 1;
	init_stack(&a_node, split_argv, argc);
	if (argc == 2)
		free_split(split_argv);
	len = stack_len(a_node);
	handle_sorted_case(&a_node, &b_node, len);
	if (!is_sorted(a_node))
		sort_stack(&a_node, &b_node, len);
	free_stack(&a_node);
	free_stack(&b_node);
	return (0);
}
