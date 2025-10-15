/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/09 13:38:26 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/25 14:53:13 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

int	ft_isalnum(int c)
{
	int	is_digit;
	int	is_alpha;

	is_alpha = ft_isalpha(c);
	is_digit = ft_isdigit(c);
	if (is_alpha == 1 || is_digit == 1)
	{
		return (1);
	}
	return (0);
}
