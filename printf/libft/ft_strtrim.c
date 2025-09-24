/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/30 11:26:53 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/30 16:00:57 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#define TRUE 1
#define FALSE 0

static int		check_exclusion_set(char const *str, const char *exclusion_set);
static size_t	get_newstr_size(const char *start_newstr,
					const char *end_newstr);
static char		*create_newstr(const char *start_newstr, const char *end_newstr,
					char *new_str);

/* 
	Returns a copy of the string with the characters specified in 
	’exclusion set’ removedfrom the beginning and the end of the string.
	If there are no valid characters it returns an empty string.
*/

char	*ft_strtrim(char const *str,
					char const *exclusion_set)
{
	const char	*start_newstr;
	const char	*end_newstr;
	char		*trimmed_str;
	size_t		size_newstr;

	if (!str || !exclusion_set)
		return (NULL);
	start_newstr = str;
	end_newstr = (str + ft_strlen(str) - 1);
	size_newstr = 0;
	while (check_exclusion_set(start_newstr, exclusion_set) == TRUE)
		start_newstr++;
	if (*start_newstr == '\0')
		return (ft_strdup(""));
	while (check_exclusion_set(end_newstr, exclusion_set) == TRUE)
		end_newstr--;
	size_newstr = get_newstr_size(start_newstr, end_newstr);
	trimmed_str = malloc(sizeof(char) * size_newstr + 1);
	if (!trimmed_str)
		return (NULL);
	trimmed_str = create_newstr(start_newstr, end_newstr, trimmed_str);
	return (trimmed_str);
}

static int	check_exclusion_set(char const *str,
								const char *exclusion_set)
{
	while (*exclusion_set)
	{
		if (*exclusion_set == *str)
			return (TRUE);
		exclusion_set++;
	}
	return (FALSE);
}

static size_t	get_newstr_size(const char *start_newstr,
								const char *end_newstr)
{
	size_t	size;

	size = 1;
	while (start_newstr != end_newstr)
	{
		size++;
		start_newstr++;
	}
	return (size);
}

static char	*create_newstr(const char *start_newstr,
							const char *end_newstr,
							char *new_str)
{
	char	*ptr_return;

	ptr_return = new_str;
	while (start_newstr != end_newstr)
	{
		*new_str = *start_newstr;
		new_str++;
		start_newstr++;
	}
	*new_str = *start_newstr;
	new_str++;
	*new_str = '\0';
	return (ptr_return);
}
