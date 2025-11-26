/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_p.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/06 10:42:27 by lilo          #+#    #+#                 */
/*   Updated: 2025/11/03 16:59:41 by lelouren      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>

/* 
	- Takes a void pointer
	- Writes a pointer address
	- Returns the number of bytes ft_printxx wrote
*/

int	ft_print_p(void *nbr)
{
	int	count;

	if (nbr == 0)
	{
		count = write(1, "(nil)", 5);
		return (count);
	}
	count = write(1, "0x", 2);
	count += ft_print_xx((unsigned long long)nbr, 'x');
	return (count);
}
