/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/30 17:31:28 by lilo          #+#    #+#                 */
/*   Updated: 2025/10/15 18:50:25 by lelouren      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
	Applies the function on each character of the string passed 
	as argument, passing its index's first argument. Each character 
	is passed by address to the function to be modified if necessary.
*/

void	ft_striteri(char *str,
					void (*function)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (str[i])
	{
		function(i, &str[i]);
		i++;
	}
}
