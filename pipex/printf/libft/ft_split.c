/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/25 12:30:57 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/25 12:43:48 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	*free_mem(int list_item_index, char **list)
{
	while (list_item_index > 0)
	{
		list_item_index--;
		free(list[list_item_index]);
	}
	free(list);
	return (NULL);
}

static int	add_to_list(const char *s, char **list, char c, size_t *index)
{
	size_t		length;
	const char	*start;

	length = 0;
	start = s;
	while (s[length] && s[length] == c)
		length++;
	start += length;
	length = 0;
	while (s[length] && s[length] != c)
		length++;
	list[*index] = ft_substr(start, 0, length);
	if (!list[*index])
		return (0);
	(*index)++;
	return (1);
}

static size_t	ft_countstring(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**list;
	size_t	num_items;
	size_t	index;

	index = 0;
	if (!s)
		return (NULL);
	num_items = ft_countstring(s, c) + 1;
	list = malloc(num_items * sizeof(char *));
	if (!list)
		return (NULL);
	while (*s)
	{
		if (*s != c && !add_to_list(s, list, c, &index))
			return (free_mem(index, list));
		while (*s && *s != c)
			s++;
		if (*s)
			s++;
	}
	list[index] = NULL;
	return (list);
}
