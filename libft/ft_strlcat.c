/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 17:09:49 by llourens      #+#    #+#                 */
/*   Updated: 2025/09/18 11:32:38 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static size_t	strlcat_dest_len(char *dst, size_t size);

/*
	Concatanates src to dest at most size - 1 (Always
	NULL terminates unless size is less than or equal to
	the length of dest)
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	return_value;
	size_t	dest_len;
	size_t	i;

	i = 0;
	dest_len = strlcat_dest_len(dst, size);
	return_value = ft_strlen(src) + dest_len;
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	while (src[i] && (dest_len + i < size - 1))
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (return_value);
}

static size_t	strlcat_dest_len(char *dst, size_t size)
{
	size_t i;

	i = 0;
	while (i < size && dst[i])
		i++;
	return (i);
}