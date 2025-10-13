/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lelouren <lelouren@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/06 12:49:14 by lelouren      #+#    #+#                 */
/*   Updated: 2025/10/13 17:10:33 by lelouren      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10

# include <stdlib.h>
# include <unistd.h>

typedef struct s_buffer
{
	char			*content;
	struct s_buffer	*next;
}					t_buffer;

/* SRC */
char				*get_next_line(int fd);
char				*fill_buffer(int fd, char *stash);
char				*extract_return(char *stash);
char				*extract_stash(char *stash);
void				ft_bzero(void *memory, size_t size);

/* Utils */
void				ft_free(char **memory);
char				*ft_strdup(const char *string);
char				*ft_strchr(const char *str, int chr);
char				*ft_strjoin(char const *str1, char const *str2);
int					ft_strlen(char *str);

#endif