/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 15:34:57 by llourens      #+#    #+#                 */
/*   Updated: 2025/10/15 18:48:51 by lelouren      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdio.h>

/* 
	Copies a string up to size from src to dst. Size - 1 characters
	will be copied and it NULL terminates.
*/

size_t	ft_strlcpy(char *dst,
				const char *src,
				size_t size)
{
	size_t		len_src;
	const char	*end;

	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	end = src + size - 1;
	while (*src && src != end)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (len_src);
}
