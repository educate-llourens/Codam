/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 09:51:04 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/21 10:28:05 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strncpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (src[i] == '\0' && i < size)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
