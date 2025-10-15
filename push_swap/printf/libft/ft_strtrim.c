/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/22 17:09:05 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/22 17:09:07 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	*cpy_empty_string(char **new_trimmed)
{
	*new_trimmed = malloc(sizeof(char) * 1);
	if (!*new_trimmed)
		return (NULL);
	(*new_trimmed)[0] = '\0';
	return (*new_trimmed);
}

static int	is_illegal(char c, char const *set)
{
	int		set_index;

	set_index = 0;
	while (set[set_index])
	{
		if (set[set_index] == c)
			return (1);
		set_index++;
	}
	return (0);
}

static int	start_trim(char const *s1, char const *set)
{
	int		current_index;

	current_index = 0;
	while (s1[current_index] && is_illegal(s1[current_index], set))
		current_index++;
	return (current_index);
}

static int	end_trim(char const *s1, char const *set, int len_str)
{
	int		current_index;

	current_index = len_str - 1;
	while (current_index >= 0 && is_illegal(s1[current_index], set))
		current_index--;
	return (current_index + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start_cpy;
	int		end_cpy;
	int		len_str;
	char	*new_trimmed;

	if (!s1 || !set)
		return (NULL);
	len_str = ft_strlen((char *)s1);
	start_cpy = start_trim(s1, set);
	end_cpy = end_trim(s1, set, len_str);
	if (start_cpy >= end_cpy)
		return (cpy_empty_string(&new_trimmed));
	new_trimmed = malloc(sizeof(char) * (end_cpy - start_cpy + 1));
	if (!new_trimmed)
		return (NULL);
	ft_strlcpy(new_trimmed, s1 + start_cpy, end_cpy - start_cpy + 1);
	return (new_trimmed);
}
