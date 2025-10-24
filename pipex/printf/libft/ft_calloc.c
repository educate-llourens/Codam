/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 09:33:43 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/25 17:43:17 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*pntr;

	pntr = malloc(num * size);
	if (pntr == NULL)
	{
		return (NULL);
	}
	ft_bzero(pntr, num * size);
	return (pntr);
}
