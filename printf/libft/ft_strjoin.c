/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/26 15:09:52 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/04 13:03:48 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdio.h>

/* 
	Creates a new string and joins the two strings in the new string.
	You will need to free the resulting string when you call the function.
*/

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*new_string;
	char	*start_newstr;

	if (!str1 || !str2)
		return (NULL);
	new_string = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!new_string)
		return (NULL);
	start_newstr = new_string;
	while (*str1)
	{
		*new_string = *str1;
		new_string++;
		str1++;
	}
	while (*str2)
	{
		*new_string = *str2;
		new_string++;
		str2++;
	}
	*new_string = '\0';
	return (start_newstr);
}
