/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/19 13:36:32 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/03 16:38:49 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
	Looks for a substring within a string and returns a pointer to the 
	first occurance of the substring.
*/

char	*ft_strnstr(const char *haystack,
						const char *needle,
						size_t size)
{
	const char		*search_end;
	char			*cursor;
	size_t			needle_len;

	if (*needle == '\0')
		return ((char *)haystack);
	if (size == (size_t)-1)
		size = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	if (size == 0)
		return (NULL);
	search_end = haystack + size;
	cursor = (char *)haystack;
	while (*cursor && cursor + needle_len <= search_end)
	{
		if (ft_strncmp(cursor, needle, needle_len) == 0)
			return (cursor);
		cursor++;
	}
	return (NULL);
}
