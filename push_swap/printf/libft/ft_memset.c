/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/09 17:07:55 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/22 11:08:48 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// memset(memory, value, bytes)
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ns;

	ns = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ns[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
