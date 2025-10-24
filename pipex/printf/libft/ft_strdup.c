/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 11:13:55 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/25 17:43:38 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_s;
	int		len_s;

	len_s = ft_strlen((char *)s);
	new_s = malloc (sizeof(char) * (len_s + 1));
	if (!new_s)
		return (NULL);
	ft_memcpy(new_s, s, len_s);
	new_s[len_s] = '\0';
	return (new_s);
}
