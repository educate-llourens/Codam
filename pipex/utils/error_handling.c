/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/15 22:12:17 by root          #+#    #+#                 */
/*   Updated: 2025/03/07 19:55:19 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"


void	perror_and_exit(char *message)
{
	perror(message);
	exit (1);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
