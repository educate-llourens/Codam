/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 12:32:02 by llourens      #+#    #+#                 */
/*   Updated: 2025/07/04 11:52:31 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Finds the length of a string */

size_t	ft_strlen(const char *string)
{
	size_t	length;

	length = 0;
	while (string[length])
		length++;
	return (length);
}
