/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 10:58:42 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/24 11:33:55 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == uc)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if (uc == '\0')
	{
		while (s[i] != '\0')
		{
			i++;
		}
		return ((char *)s + i);
	}
	return (NULL);
}
