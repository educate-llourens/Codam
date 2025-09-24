/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 11:16:05 by llourens      #+#    #+#                 */
/*   Updated: 2025/06/20 10:05:56 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Checks if the character is an alphabetic letter */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
