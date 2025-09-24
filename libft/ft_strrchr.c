/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/06 15:19:18 by llourens      #+#    #+#                 */
/*   Updated: 2025/07/08 12:27:53 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/* Looks for a character in a string starting from the end of the string */

char	*ft_strrchr(const char *str,
					int chr)
{
	const char	*end_of_str;

	end_of_str = str + ft_strlen(str);
	while (end_of_str != str
		&& (unsigned char)*end_of_str != (unsigned char)chr)
		end_of_str--;
	if ((unsigned char)*end_of_str == (unsigned char)chr)
		return ((char *)end_of_str);
	return (NULL);
}
