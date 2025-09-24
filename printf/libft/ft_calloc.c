/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/20 13:54:55 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/04 11:07:09 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
	Allocates memory and fills it with zeros. Accommodates for
	integer overflow. 
*/

void	*ft_calloc(size_t nbrof_items, size_t size_item)
{
	void	*memory;

	if (nbrof_items != 0 && nbrof_items > SIZE_MAX / size_item)
		return (NULL);
	memory = malloc(nbrof_items * size_item);
	if (!memory)
		return (NULL);
	if ((ssize_t)nbrof_items < 0)
		return (memory);
	ft_bzero(memory, (nbrof_items * size_item));
	return (memory);
}
