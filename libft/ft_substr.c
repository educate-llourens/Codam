/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lionesslilo <lionesslilo@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/20 19:08:16 by lionesslilo   #+#    #+#                 */
/*   Updated: 2025/06/26 14:46:18 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
    Allocates memory for the substring and returns the substring from the 
    string. The substring begins at start and is maximum size of len. 
*/

char	*ft_substr(char const *string, unsigned int start, size_t len)
{
	char		*substring;
	const char	*substring_start;
	char		*exception;
	size_t		len_str;

	if (!string)
		return (NULL);
	len_str = ft_strlen(string);
	if (len_str < start)
	{
		exception = ft_strdup("");
		return (exception);
	}
	if (len > (len_str - start))
		len = len_str - start;
	substring = malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	substring_start = string + start;
	ft_strlcpy(substring, substring_start, len + 1);
	return (substring);
}
