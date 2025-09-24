/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 11:13:32 by llourens      #+#    #+#                 */
/*   Updated: 2025/09/18 11:11:42 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
size_t				ft_strlen(const char *string);
void				*ft_memset(void *memory, int filler, size_t size);
void				ft_bzero(void *memory, size_t size);
void				*ft_memcpy(void *dest, const void *src, size_t size);
void				*ft_memmove(void *dest, const void *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_toupper(int chr);
int					ft_tolower(int chr);
char				*ft_strchr(const char *str, int chr);
char				*ft_strrchr(const char *str, int chr);
int					ft_strncmp(const char *str_1, const char *str_2,
						size_t size);
void				*ft_memchr(const void *str, int byte, size_t size);
int					ft_memcmp(const void *str_1, const void *str_2,
						size_t size);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t size);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t nbrof_items, size_t size_item);
char				*ft_strdup(const char *string);
char				*ft_substr(char const *string, unsigned int start,
						size_t len);
char				*ft_strjoin(char const *str1, char const *str2);
char				*ft_itoa(int nbr);
char				*ft_strtrim(char const *str, char const *exclusion_set);
char				*ft_strmapi(char const *str, char (*function)(unsigned int,
							char));
void				ft_striteri(char *str, void (*function)(unsigned int,
							char *));
char				**ft_split(char const *str, char chr);
void				ft_putchar_fd(char chr, int fd);
void				ft_putstr_fd(char *str, int fd);
void				ft_putendl_fd(char *str, int fd);
void				ft_putnbr_fd(int nbr, int fd);

/* Bonus */
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **list, t_list *new);
int					ft_lstsize(t_list *list);
t_list				*ft_lstlast(t_list *list);
void				ft_lstadd_back(t_list **list, t_list *new);
void				ft_lstdelone(t_list *list, void (*del)(void *));
void				ft_lstclear(t_list **list, void (*del)(void *));
void				ft_lstiter(t_list *list, void (*function)(void *));
t_list				*ft_lstmap(t_list *list, void *(*function)(void *),
						void (*del)(void *));

#endif