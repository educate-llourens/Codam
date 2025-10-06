/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lelouren <lelouren@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/06 12:52:10 by lelouren      #+#    #+#                 */
/*   Updated: 2025/10/06 14:47:55 by lelouren      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strdup(const char *s);
char		*ft_strchr(const char *s, int c);
t_buffer	*create_node(void);
char		*ft_strjoin(char const *str1, char const *str2);

void	ft_free(char **memory)
{
	if (*memory)
	{
		free(*memory);
		*memory = NULL;
	}
}


char	*ft_strdup(const char *s)
{
	char	*new_s;
	int		len_s;
	int		i;

	len_s = ft_strlen((char *)s);
	new_s = malloc(sizeof(char) * (len_s + 1));
	if (!new_s)
		return (NULL);
	i = 0;
	while (i < len_s)
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[len_s] = '\0';
	return (new_s);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == uc)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if (uc == '\0')
	{
		while (s[i] != '\0')
		{
			i++;
		}
		return ((char *)s + i);
	}
	return (NULL);
}

t_buffer	*create_node(void)
{
	t_buffer	*new_node;

	new_node = malloc(sizeof(t_buffer));
	if (!new_node)
		return (NULL);
	new_node->content[0] = '\0';
	new_node->next = NULL;
	return (new_node);
}

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
