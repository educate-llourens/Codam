/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/07 17:32:01 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/08 12:27:23 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Outputs the integer ’n’ to the given filedescriptor. */

static int	exceptions(int nbr, int fd);

void	ft_putnbr_fd(int nbr,
				int fd)
{
	char	remainder;

	if (exceptions(nbr, fd) == 1)
		return ;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr *= -1;
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	remainder = (nbr % 10) + '0';
	write(fd, &remainder, 1);
}

static int	exceptions(int nbr,
					int fd)
{
	if (nbr == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	if (nbr == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	return (0);
}
