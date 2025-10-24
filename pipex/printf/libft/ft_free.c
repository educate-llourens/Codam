/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/18 16:18:08 by llourens      #+#    #+#                 */
/*   Updated: 2024/12/18 16:23:23 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_free(char **memory)
{
	if (*memory)
	{
		free(*memory);
		*memory = NULL;
	}
}
