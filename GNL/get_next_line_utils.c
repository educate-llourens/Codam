/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lelouren <lelouren@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/06 12:52:10 by lelouren      #+#    #+#                 */
/*   Updated: 2025/10/13 17:03:13 by lelouren      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *string);
char	*ft_strchr(const char *str, int chr);
char	*ft_strjoin(char const *str1, char const *str2);
int		ft_strlen(char *str);

void	ft_free(char **memory)
{
	if (*memory)
	{
		free(*memory);
		*memory = NULL;
	}
}

char	*ft_strdup(const char *string)
{
	char	*new_s;
	int		len_s;
	int		i;

	len_s = ft_strlen((char *)string);
	new_s = malloc(sizeof(char) * (len_s + 1));
	if (!new_s)
		return (NULL);
	i = 0;
	while (i < len_s)
	{
		new_s[i] = string[i];
		i++;
	}
	new_s[len_s] = '\0';
	return (new_s);
}

char	*ft_strchr(const char *str, int chr)
{
	while (*str)
	{
		if ((unsigned char)*str == (unsigned char)chr)
			return ((char *)str);
		str++;
	}
	if ((unsigned char)chr == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*new_string;
	char	*start_newstr;

	if (!str1 || !str2)
		return (NULL);
	new_string = malloc(sizeof(char) * (ft_strlen((char *)str1)
				+ ft_strlen((char *)str2) + 1));
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
