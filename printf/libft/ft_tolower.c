/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/06 14:46:04 by llourens      #+#    #+#                 */
/*   Updated: 2025/06/20 11:18:32 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Coverts a character from uppercase to lowercase */

int	ft_tolower(int chr)
{
	if (chr >= 'A' && chr <= 'Z')
		chr += 32;
	return (chr);
}
