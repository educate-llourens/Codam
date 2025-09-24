/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 14:15:47 by llourens      #+#    #+#                 */
/*   Updated: 2025/06/23 15:54:39 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*Erases the data by filling size bytes of memory with zeros*/

void	ft_bzero(void *memory,
				size_t size)
{
	size_t			i;
	unsigned char	*uc_buffer;

	i = 0;
	if (size == 0)
		return ;
	uc_buffer = (unsigned char *)memory;
	while (i < size)
	{
		uc_buffer[i] = '\0';
		i++;
	}
}
