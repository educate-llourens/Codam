/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lelouren <lelouren@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/06 12:48:58 by lelouren      #+#    #+#                 */
/*   Updated: 2025/10/06 14:54:37 by lelouren      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_stash(int fd, char *stash);
char	*extract_line(t_buffer *list);
char	*next_line(char *stash);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*return_line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free(&stash), NULL);
	if (!stash)
	{
		stash = ft_strdup("");
		if (!stash)
			return (free(stash), NULL);
	}
	stash = fill_stash(fd, stash);
	return_line = next_line(stash);
	while (*stash && *stash != '\n')
		stash++;
	stash++;
	return(return_line);
}

char	*fill_stash(int fd, char *stash)
{
	t_buffer	*buffer_list;
	t_buffer	*new_node;
	int			bytes_read;
	char		*str;
	char		*return_str;

	new_node = create_node();
	buffer_list = new_node;
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(new_node->content, '\n'))
	{
		if (read(fd, new_node->content, BUFFER_SIZE) < 0)
			return (free_list(buffer_list), NULL);
		if (ft_strchr(new_node->content, '\n'))
			continue ;
		new_node->next = create_node();
		new_node = new_node->next;
	}
	str = extract_line(buffer_list);
	if (!str)
		return (NULL);
	return_str = ft_strjoin(stash, str);
	return (return_str);
}

char	*extract_line(t_buffer *list)
{
	char		*str;
	t_buffer	*list_start;
	int			i;

	i = 0;
	list_start = list;
	while (list)
	{
		while (list->content[i])
			i++;
		list = list->next;
	}
	str = malloc((sizeof(char *) * i) + 1);
	if (!str)
		return (NULL);
	list = list_start;
	while (list)
	{
		str = ft_strjoin(str, list->content);
		list = list->next;
	}
	free_list(list_start);
	return (str);
}

char	*next_line(char *stash)
{
	char	*next_line;
	int		i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	next_line = malloc((sizeof(char) * i) + 1);
	if (!next_line)
		return (free(stash), NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		next_line[i] = stash[i];
		i++;
	}
	next_line[i] = '\0';
	return (next_line);
}

void	free_list(t_buffer *list)
{
	t_buffer	*temp;

	if (!list)
		return ;
	while (list)
	{
		temp = (list)->next;
		free(list->content);
		free(list);
		list = temp;
	}
}
