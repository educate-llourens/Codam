/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/02 16:50:04 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/07 18:17:00 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_putendl_fd(char *str,
					int fd)
{
	if (!str || fd == -1)
		return ;
	ft_putstr_fd(str, fd);
	write(fd, "\n", 1);
}
