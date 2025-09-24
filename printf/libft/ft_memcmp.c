/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/06 20:05:23 by llourens      #+#    #+#                 */
/*   Updated: 2025/06/24 16:40:06 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/* Returns the difference between two pieces of memory */

int	ft_memcmp(const void *str_1,
			const void *str_2,
			size_t size)
{
	size_t			i;
	unsigned char	*uc_str_1;
	unsigned char	*uc_str_2;

	if (size == 0)
		return (0);
	i = 0;
	uc_str_1 = (unsigned char *)str_1;
	uc_str_2 = (unsigned char *)str_2;
	while (i < size)
	{
		if (*uc_str_1 != *uc_str_2)
			return (*uc_str_1 - *uc_str_2);
		uc_str_1++;
		uc_str_2++;
		i++;
	}
	return (0);
}
