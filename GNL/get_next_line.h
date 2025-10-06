/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lelouren <lelouren@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/06 12:49:14 by lelouren      #+#    #+#                 */
/*   Updated: 2025/10/06 13:56:48 by lelouren      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10

# include <stdlib.h>
# include <unistd.h>

typedef struct s_buffer
{
	char		*content;
	s_buffer	*next;
}				t_buffer;

/* SRC */
void			ft_free(char **memory);
char			*fill_stash(int fd, char *stash);
char			*ft_strchr(const char *s, int c);

/* Utils */
char			*ft_strdup(const char *s);

#endif