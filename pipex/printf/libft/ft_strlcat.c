/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/24 14:59:39 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/25 10:02:15 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	size_of_src;
	size_t	size_of_dst;

	size_of_src = ft_strlen(src);
	size_of_dst = ft_strlen(dst);
	if (dstsize <= size_of_dst)
		return (dstsize + size_of_src);
	if (size_of_src < dstsize - size_of_dst)
		ft_memcpy(dst + size_of_dst, src, size_of_src + 1);
	else
	{
		ft_memcpy(dst + size_of_dst, src, dstsize - size_of_dst - 1);
		dst[dstsize - 1] = '\0';
	}
	return (size_of_dst + size_of_src);
}
