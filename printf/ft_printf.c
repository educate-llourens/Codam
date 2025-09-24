/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/28 15:06:52 by llourens      #+#    #+#                 */
/*   Updated: 2025/09/18 12:08:36 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	is_valid(int c);
static int	print_from_specifier(char specifier, va_list arg_pointer);

/* 
	- Takes in a string, with a specifier, and variable arguments
	- prints like printf would
	- Returns the nymber of bytes it printed
*/

int	ft_printf(const char *str, ...)
{
	va_list	arg_pointer;
	int		count;

	if (!str)
		return (0);
	count = 0;
	va_start(arg_pointer, str);
	while (*str)
	{
		if (*str == '%' && is_valid(*++str))
			count += print_from_specifier(*str, arg_pointer);
		else
			count += write(1, str, 1);
		str++;
	}
	va_end(arg_pointer);
	return (count);
}

static int	is_valid(int c)
{
	char	*valid_options;

	valid_options = "cspdiuxX%";
	while (*valid_options)
	{
		if (c == *valid_options)
			return (1);
		valid_options++;
	}
	return (0);
}

static int	print_from_specifier(char specifier, va_list arg_pointer)
{
	int	count_from_specifier;

	count_from_specifier = 0;
	if (specifier == 'c')
		count_from_specifier += ft_print_c(va_arg(arg_pointer, int));
	else if (specifier == 's')
		count_from_specifier += ft_print_str(va_arg(arg_pointer, char *));
	else if (specifier == 'p')
		count_from_specifier += ft_print_p(va_arg(arg_pointer, void *));
	else if (specifier == 'd' || specifier == 'i')
		count_from_specifier += ft_print_di(va_arg(arg_pointer, int));
	else if (specifier == 'u')
		count_from_specifier += ft_print_u(va_arg(arg_pointer, unsigned long));
	else if (specifier == 'x' || specifier == 'X')
		count_from_specifier += ft_print_xx((unsigned int)va_arg(arg_pointer,
					unsigned long int), specifier);
	else if (specifier == '%')
		count_from_specifier += write(1, "%", 1);
	return (count_from_specifier);
}
