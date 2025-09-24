/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/06 19:32:30 by llourens      #+#    #+#                 */
/*   Updated: 2025/07/03 13:20:40 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/* 
	Locates the first occurance of byte in the initial size bytes 
	pointed to by str.
*/

void	*ft_memchr(const void *str,
					int byte,
					size_t size)
{
	size_t				i;
	const unsigned char	*cuc_str;

	i = 0;
	if (size == 0)
		return (NULL);
	cuc_str = (unsigned char *)str;
	while (i < size)
	{
		if (*cuc_str == (unsigned char)byte)
			return ((void *)cuc_str);
		cuc_str++;
		i++;
	}
	return (NULL);
}
