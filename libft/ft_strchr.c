/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/06 14:54:14 by llourens      #+#    #+#                 */
/*   Updated: 2025/07/08 15:25:16 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/* Returns a pointer to the first occurance of the character in the string */

char	*ft_strchr(const char *str,
					int chr)
{
	while (*str)
	{
		if ((unsigned char)*str == (unsigned char)chr)
			return ((char *)str);
		str++;
	}
	if ((unsigned char)chr == '\0')
		return ((char *)str);
	return (NULL);
}
