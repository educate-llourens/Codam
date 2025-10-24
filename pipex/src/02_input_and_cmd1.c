/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   02_input_and_cmd1.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/25 15:09:58 by llourens      #+#    #+#                 */
/*   Updated: 2025/10/24 10:27:05 by lelouren      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

/*
	- Takes in the struct and the command
	- Closes necessary pipes
	- Runs execve
	- If execve fails it cleans up
*/

void	input_and_cmd1(t_pipex pipe_data, char *orig_cmd1)
{
	char	**cmd_with_flags;

	close(pipe_data.pipe_read);
	dup2(pipe_data.fd_input_file, STDIN_FILENO);
	dup2(pipe_data.pipe_write, STDOUT_FILENO);
	cmd_with_flags = ft_split(orig_cmd1, ' ');
	if (execve(pipe_data.cmd1, cmd_with_flags, pipe_data.environment) == -1)
	{
		close(pipe_data.fd_input_file);
		close(pipe_data.pipe_write);
		free_split(cmd_with_flags);
	}
}
