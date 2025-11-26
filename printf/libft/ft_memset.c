/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 12:48:30 by llourens      #+#    #+#                 */
/*   Updated: 2025/09/18 11:07:48 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/* Fills the memory up to size with the filler */

void	*ft_memset(void *memory, int filler, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (memory);
	while (i < size)
	{
		((unsigned char *)memory)[i] = (unsigned char)filler;
		i++;
	}
	return (memory);
}
