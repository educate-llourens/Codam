/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_u.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/20 00:38:11 by llourens      #+#    #+#                 */
/*   Updated: 2025/11/03 16:55:37 by lelouren      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf.h"

/* 
	- Takes an unsigned int
	- Writes the unsigned int
	- Returns the number of bytes it wrote 
*/

int	ft_print_u(unsigned int nbr)
{
	char	remainder;
	int		count;

	count = 0;
	if (nbr >= 10)
		count += ft_print_u(nbr / 10);
	remainder = (nbr % 10) + '0';
	count += write(1, &remainder, 1);
	return (count);
}
