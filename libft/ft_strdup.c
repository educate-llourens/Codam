/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/20 17:49:39 by lionesslilo   #+#    #+#                 */
/*   Updated: 2025/07/08 16:38:19 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/* 
    Returns a pointer to a new string which is a duplicate of string. It needs 
    to allocate memory for the new string and you need to free your strdup.
*/

char	*ft_strdup(const char *string)
{
	size_t	str_len;
	char	*str_duplicated;
	char	*end;

	str_len = ft_strlen(string);
	str_duplicated = malloc(str_len + 1 * sizeof(char));
	if (!str_duplicated)
		return (NULL);
	ft_memcpy(str_duplicated, string, (str_len + 1));
	end = str_duplicated + str_len;
	*end = '\0';
	return (str_duplicated);
}
