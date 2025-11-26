/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/02 16:50:04 by lilo          #+#    #+#                 */
/*   Updated: 2025/10/15 18:54:58 by lelouren      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/* 
	Writes a string and moves to the next line in the given file 
	pointed to by the file descriptor
*/

void	ft_putendl_fd(char *str, int fd)
{
	if (fd == -1)
		return ;
	ft_putstr_fd(str, fd);
	write(fd, "\n", 1);
}
