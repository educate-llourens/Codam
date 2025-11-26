/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/02 14:56:01 by lilo          #+#    #+#                 */
/*   Updated: 2025/09/18 11:30:46 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/* Puts a char in the file pointed to by the file descriptor */

void	ft_putchar_fd(char chr, int fd)
{
	if (fd == -1)
		return ;
	write(fd, &chr, 1);
}
