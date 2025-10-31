/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lelouren <lelouren@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/06 12:48:58 by lelouren      #+#    #+#                 */
/*   Updated: 2025/10/31 13:55:52 by lelouren      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*fill_buffer(int fd, char *stash);
char	*extract_return(char *stash);
char	*extract_stash(char *stash);
void	ft_bzero(void *memory, size_t size);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*return_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free(&stash), NULL);
	if (!stash)
	{
		stash = ft_strdup("");
		if (!stash)
			return (ft_free(&stash), NULL);
	}
	stash = fill_buffer(fd, stash);
	if (!stash)
		return (NULL);
	if (stash[0] == '\0')
		return (ft_free(&stash), NULL);
	return_line = extract_return(stash);
	if (!return_line)
		return (ft_free(&stash), NULL);
	stash = extract_stash(stash);
	return (return_line);
}

char	*fill_buffer(int fd, char *stash)
{
	char	*fetched_buffer;
	char	*joined_str;
	int		bytes_read;

	bytes_read = 1;
	fetched_buffer = NULL;
	fetched_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!fetched_buffer)
		return (ft_free(&stash), NULL);
	ft_bzero(fetched_buffer, BUFFER_SIZE + 1);
	while (bytes_read > 0 && !ft_strchr(fetched_buffer, '\n'))
	{
		bytes_read = read(fd, fetched_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_free(&stash), ft_free(&fetched_buffer), NULL);
		fetched_buffer[bytes_read] = '\0';
		joined_str = ft_strjoin(stash, fetched_buffer);
		if (!joined_str)
			return (ft_free(&fetched_buffer), ft_free(&stash), NULL);
		ft_free(&stash);
		stash = joined_str;
	}
	return (ft_free(&fetched_buffer), stash);
}

char	*extract_return(char *stash)
{
	int		i;
	char	*return_line;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	return_line = malloc(sizeof(char) * (i + 1));
	if (!return_line)
		return (ft_free(&stash), NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		return_line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		return_line[i++] = '\n';
	return_line[i] = '\0';
	return (return_line);
}

char	*extract_stash(char *stash)
{
	char	*new_stash;
	int		i;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && (stash[i] != '\n'))
		i++;
	if (stash[i] == '\0')
		return (ft_free(&stash), NULL);
	i++;
	new_stash = ft_strdup(stash + i);
	if (!new_stash)
		return (ft_free(&stash), NULL);
	ft_free(&stash);
	return (new_stash);
}

void	ft_bzero(void *memory, size_t size)
{
	size_t			i;
	unsigned char	*uc_buffer;

	i = 0;
	if (size == 0)
		return ;
	uc_buffer = (unsigned char *)memory;
	while (i < size)
	{
		uc_buffer[i] = '\0';
		i++;
	}
}
