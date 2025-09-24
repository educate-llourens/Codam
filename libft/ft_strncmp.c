/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/06 18:22:28 by llourens      #+#    #+#                 */
/*   Updated: 2025/07/08 16:34:17 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/* Compares two strings up to size and returns the difference */

int	ft_strncmp(const char *str_1,
				const char *str_2,
				size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if ((unsigned char)str_1[i] == '\0' || (unsigned char)str_2[i] == '\0')
			return ((unsigned char)str_1[i] - (unsigned char)str_2[i]);
		if (((unsigned char)str_1[i] < (unsigned char)str_2[i])
			|| ((unsigned char)str_1[i] > (unsigned char)str_2[i]))
			return ((unsigned char)str_1[i] - (unsigned char)str_2[i]);
		i++;
	}
	return (0);
}
