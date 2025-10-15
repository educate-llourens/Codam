/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/20 00:38:11 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/25 14:53:22 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

static char	*initialise_string(int nb, int int_len)
{
	char	*new_str;

	new_str = malloc(sizeof(char) * (int_len + 1));
	if (!new_str)
		return (NULL);
	if (nb < 0)
	{
		new_str[int_len - 1] = '-';
	}
	return (new_str);
}

static char	*flip_string(char *new_str, int int_len)
{
	int		i;
	char	temp;

	i = 0;
	while (i < (int_len / 2))
	{
		temp = new_str[i];
		new_str[i] = new_str[int_len - (i + 1)];
		new_str[int_len - (i + 1)] = temp;
		i++;
	}
	return (new_str);
}

static char	*units_and_flip(char *new_str, int nb, int int_len, int i )
{
	new_str[i] = (nb % 10) + '0';
	new_str = flip_string(new_str, int_len);
	new_str[int_len] = '\0';
	return (new_str);
}

static int	int_size(int nb)
{
	int	size;

	size = 1;
	if (nb < 0)
	{
		size++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int nb)
{
	int		remainder;
	int		int_len;
	char	*new_str;
	int		i;

	i = 0;
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	int_len = int_size(nb);
	new_str = initialise_string(nb, int_len);
	if (!new_str)
		return (NULL);
	if (nb < 0)
		nb = -nb;
	while (nb / 10)
	{
		remainder = nb % 10;
		new_str[i] = remainder + '0';
		i++;
		nb = nb / 10;
	}
	units_and_flip(new_str, nb, int_len, i);
	return (new_str);
}
