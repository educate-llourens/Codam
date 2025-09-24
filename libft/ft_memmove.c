/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 15:05:03 by llourens      #+#    #+#                 */
/*   Updated: 2025/07/08 15:14:49 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/* Moves memory up to size from src to dest */

void	*ft_memmove(void *dest,
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
	if (dest < src)
		ft_memcpy(uc_dest, uc_src, size);
	else
	{
		src_i = size;
		dest_i = size;
		while (src_i > 0)
		{
			src_i--;
			dest_i--;
			uc_dest[dest_i] = uc_src[src_i];
		}
	}
	return (dest);
}
