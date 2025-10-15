/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 13:26:21 by llourens      #+#    #+#                 */
/*   Updated: 2024/12/29 22:23:53 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#define BUFFER_SIZE 10

// void	ft_free(char **memory)
// {
// 	if (*memory)
// 	{
// 		free(*memory);
// 		*memory = NULL;
// 	}
// }

static char	*leftover_stash(char *stash)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!stash)
		return (NULL);
	while (stash && stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (ft_free(&stash), NULL);
	line = malloc((ft_strlen(stash) - i + 1) * sizeof(char));
	if (!line)
		return (ft_free(&stash), NULL);
	i++;
	while (stash[i] != '\0')
		line[j++] = stash[i++];
	line[j] = '\0';
	ft_free(&stash);
	return (line);
}

static char	*get_line_from_buffer(char *stash)
{
	char	*line;
	int		len;
	int		i;

	if (ft_strchr(stash, '\n'))
		len = ft_strchr(stash, '\n') - stash + 1;
	else
		len = ft_strlen(stash);
	i = 0;
	if (!stash)
		return (NULL);
	line = malloc(len + 1);
	if (!line)
		return (ft_free(&stash), NULL);
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*read_and_fill_buffer(int fd, char *stash)
{
	char	*cup_buffer;
	char	*temp;
	int		chars_read;

	cup_buffer = NULL;
	cup_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!cup_buffer)
		return (free(stash), NULL);
	ft_memset(cup_buffer, 0, BUFFER_SIZE + 1);
	chars_read = 1;
	while (chars_read > 0 && !ft_strchr(cup_buffer, '\n'))
	{
		chars_read = read(fd, cup_buffer, BUFFER_SIZE);
		if (chars_read == -1)
			return (free(cup_buffer), ft_free(&stash), NULL);
		cup_buffer[chars_read] = 0;
		temp = ft_strjoin(stash, cup_buffer);
		if (!temp)
			return (ft_free(&cup_buffer), ft_free(&stash), NULL);
		free(stash);
		stash = temp;
	}
	ft_free(&cup_buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free(&stash), NULL);
	if (!stash)
	{
		stash = ft_strdup("");
		if (!stash)
			return (ft_free(&stash), NULL);
	}
	stash = read_and_fill_buffer(fd, stash);
	if (!stash)
		return (NULL);
	if (*stash == '\0')
		return (ft_free(&stash), NULL);
	line = get_line_from_buffer(stash);
	if (!line)
		return ((stash = NULL), NULL);
	stash = leftover_stash(stash);
	return (line);
}
