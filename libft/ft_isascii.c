/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 12:10:37 by llourens      #+#    #+#                 */
/*   Updated: 2025/06/20 10:19:31 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Checks if it is within the ascii character set */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
