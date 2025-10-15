/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_xx.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 14:03:31 by llourens      #+#    #+#                 */
/*   Updated: 2024/12/18 17:05:48 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

static int	ft_putnbr(unsigned int n, int fd)
{
	char	str;
	int		count;

	count = 0;
	if (n >= 10)
	{
		ft_putnbr(n / 10, fd);
		str = '0' + n % 10;
	}
	else
		str = '0' + n;
	count += write(fd, &str, 1);
	return (count);
}

int	ft_print_xx(unsigned long int nb, char specifier)
{
	char	number;
	int		count;

	count = 0;
	if (nb >= 16)
	{
		count += ft_print_xx(nb / 16, specifier);
		count += ft_print_xx((nb % 16), specifier);
		return (count);
	}
	if (nb <= 9)
		return (count + ft_putnbr(nb, 1));
	number = nb + 55;
	if (specifier == 'x')
		number = nb + 87;
	count += write(1, &number, 1);
	return (count);
}
