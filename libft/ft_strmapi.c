/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/30 16:23:12 by lilo          #+#    #+#                 */
/*   Updated: 2025/09/18 11:33:52 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
Applies the function to each character of the string, passing its index
as the first argument and the character itself as the second. A newstring is 
created (using malloc) to collect the results from the successive 
applications of the function.
*/

char	*ft_strmapi(char const *str,
					char (*function)(unsigned int, char))
{
	char			*new_str;
	unsigned int	i;

	i = 0;
	if (!str || !function)
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		new_str[i] = function(i, str[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
