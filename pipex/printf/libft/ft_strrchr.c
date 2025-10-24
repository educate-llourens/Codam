/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 11:53:28 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/24 12:46:12 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	s_len;

	if (c > 256)
		c %= 256;
	s_len = ft_strlen((char *)s);
	if (c == '\0')
		return ((char *)&s[s_len]);
	i = s_len - 1;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
