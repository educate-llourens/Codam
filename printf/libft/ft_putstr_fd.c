/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/02 16:12:01 by lilo          #+#    #+#                 */
/*   Updated: 2025/09/18 11:31:25 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/* Writes a string to the file pointed to by the file descriptor. */

void	ft_putstr_fd(char *str,
				int fd)
{
	if (!str || fd == -1)
		return ;
	while (*str)
	{
		write(fd, &*str, 1);
		str++;
	}
}
