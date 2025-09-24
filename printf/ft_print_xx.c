/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_xx.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 14:03:31 by llourens      #+#    #+#                 */
/*   Updated: 2025/09/18 12:09:43 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	ft_putnbr(unsigned int nbr);

/* Prints the hex number in lowercase */

int	ft_print_xx(unsigned long int nb, char specifier)
{
	char	number;
	int		count;

	count = 0;
	if (nb >= 16)
		count += ft_print_xx(nb / 16, specifier);
	nb = nb % 16;
	if (nb <= 9)
		return (count + ft_putnbr(nb));
	number = nb + 55;
	if (specifier == 'x')
		number = nb + 87;
	count += write(1, &number, 1);
	return (count);
}

static int	ft_putnbr(unsigned int nbr)
{
	char remainder;
	int count;

	count = 0;
	if (nbr >= 10)
		count += ft_putnbr(nbr / 10);
	remainder = (nbr % 10) + '0';
	count += write(1, &remainder, 1);
	return (count);
}