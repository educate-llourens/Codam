/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/14 08:36:32 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/17 09:11:10 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i_big;
	size_t	i_little;
	size_t	len_little;

	i_big = 0;
	i_little = 0;
	len_little = ft_strlen((char *)little);
	if (len_little == 0)
	{
		return ((char *)big);
	}
	while (i_big < len && big[i_big] != '\0')
	{
		if (big[i_big] == little[i_little])
		{
			if (i_big + len_little <= len
				&& ft_strncmp(&big[i_big], little, len_little) == 0)
				return ((char *)&big[i_big]);
		}
		i_big++;
	}
	return (NULL);
}
