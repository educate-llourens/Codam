/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_str.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 09:24:29 by lilo          #+#    #+#                 */
/*   Updated: 2025/11/04 09:28:32 by lelouren      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

/* 
	- Takes in a string
	- Writes the string
	- returns the number of bytes it wrote
*/

int	ft_print_str(char *str)
{
	int	count;

	if (!str)
		str = "(null)";
	count = 0;
	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}
	return (count);
}
