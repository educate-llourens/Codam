/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/06 14:23:30 by llourens      #+#    #+#                 */
/*   Updated: 2025/06/20 11:19:18 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Converts a lowercase letter to uppercase */

int	ft_toupper(int chr)
{
	if (chr >= 'a' && chr <= 'z')
		chr -= 32;
	return (chr);
}
