/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/01 10:01:00 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/08 16:47:02 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Allocates (with malloc) and returns an array of strings obtained 
	by splitting ’s’ using the character ’c’ as a delimiter. The array 
	must end with a NULL pointer.
*/

static size_t	find_list_size(const char *str, char chr);
static size_t	get_item_len(const char *str, char chr);
static char		**populate_list(const char *str, char chr, char **list);
static void		free_list(char **list_start, char **list);

char	**ft_split(char const *str,
					char chr)
{
	char	**list;

	if (!str)
		return (NULL);
	list = malloc(sizeof(char *) * (find_list_size(str, chr) + 1));
	if (!list)
		return (NULL);
	list = populate_list(str, chr, list);
	return (list);
}

static char	**populate_list(const char *str,
							char chr,
							char **list)
{
	size_t	item_len;
	char	**list_start;

	list_start = list;
	while (*str)
	{
		while (*str == chr)
			str++;
		if (*str == '\0')
			break ;
		item_len = get_item_len(str, chr);
		*list = malloc(sizeof(char) * (item_len + 1));
		if (!*list)
		{
			free_list(list_start, list);
			return (NULL);
		}
		ft_strlcpy(*list, str, item_len + 1);
		str = str + item_len;
		list++;
	}
	*list = NULL;
	return (list_start);
}

static size_t	find_list_size(const char *str,
							char chr)
{
	size_t	nbr_items;

	nbr_items = 0;
	if (*str == '\0')
		return (0);
	if (str[0] == chr)
		while (*str == chr)
			str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str == chr && *(str + 1) != chr)
			nbr_items++;
		str++;
	}
	if (*(str - 1) != chr)
		nbr_items++;
	return (nbr_items);
}

static size_t	get_item_len(const char *str,
							char chr)
{
	size_t	len;

	len = 0;
	while (*str == chr)
		str++;
	while (*str)
	{
		if (*str == chr)
			return (len);
		len++;
		str++;
	}
	return (len);
}

static void	free_list(char **list_start,
					char **list)
{
	char	**item;

	item = list_start;
	while (item < list)
		free(*item++);
	free(list_start);
}
