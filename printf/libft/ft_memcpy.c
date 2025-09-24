/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 14:37:04 by llourens      #+#    #+#                 */
/*   Updated: 2025/07/08 15:12:24 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/* Copies memory up to size from src to dest */

void	*ft_memcpy(void *dest,
					const void *src,
					size_t size)
{
	size_t			src_i;
	size_t			dest_i;
	unsigned char	*uc_dest;
	unsigned char	*uc_src;

	src_i = 0;
	dest_i = 0;
	if ((!dest && !src) || size == 0)
		return (dest);
	uc_dest = (unsigned char *)dest;
	uc_src = (unsigned char *)src;
	while (src_i < size)
	{
		uc_dest[dest_i] = uc_src[src_i];
		src_i++;
		dest_i++;
	}
	return (dest);
}
