/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/02 16:12:01 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/03 10:26:35 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

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
