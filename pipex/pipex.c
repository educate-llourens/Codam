/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/15 19:17:46 by llourens      #+#    #+#                 */
/*   Updated: 2025/10/24 10:08:31 by lelouren      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	populate_pipe_data(t_pipex *pipe_data, int fd_pipe[2], char **argv,
			char **env);
int		forks(t_pipex pipedata, char **argv);

/*
	- Takes in user input (input_file cmd1 cmd2 out_file) and environment
	variable.
	- Delegates the input checking, populating the struct and the forks
	- Cleans up at the end
	- Returns the child's exit status if there is one or 0 if successful
*/

int	main(int argc, char **argv, char **env)
{
	int		fd_pipe[2];
	t_pipex	pipe_data;
	int		forks_return;

	input_checks(&pipe_data, argc, argv, env);
	if (pipe(fd_pipe) < 0)
		perror_and_exit("Failed to pipe");
	populate_pipe_data(&pipe_data, fd_pipe, argv, env);
	forks_return = forks(pipe_data, argv);
	if (forks_return)
		return(forks_return);
	free(pipe_data.cmd1);
	free(pipe_data.cmd2);
	return (0);
}

void	populate_pipe_data(t_pipex *pipe_data, int fd_pipe[2], char **argv,
		char **env)
{
	char	**cmd1_split;
	char	**cmd2_split;

	cmd1_split = ft_split(argv[2], ' ');
	cmd2_split = ft_split(argv[3], ' ');
	pipe_data->pipe_read = fd_pipe[0];
	pipe_data->pipe_write = fd_pipe[1];
	pipe_data->fd_input_file = open(argv[1], O_RDONLY);
	pipe_data->cmd1 = get_cmd_path(cmd1_split[0], env);
	pipe_data->cmd2 = get_cmd_path(cmd2_split[0], env);
	if (!pipe_data->cmd1 || !pipe_data->cmd2)
		perror("Failed to find command");
	pipe_data->environment = env;
	free_split(cmd1_split);
	free_split(cmd2_split);
}

int	forks(t_pipex pipedata, char **argv)
{
	pid_t	pid_fork1;
	pid_t	pid_fork2;
	int		status;

    pid_fork1 = fork();
    if (pid_fork1 < 0)
        perror_and_exit("Failed to fork");
    if (pid_fork1 == 0)
        input_and_cmd1(pipedata, argv[2]);
    pid_fork2 = fork();
    if (pid_fork2 < 0)
        perror_and_exit("Failed to fork");
    if (pid_fork2 == 0)
        output_and_cmd2(pipedata, argv[3]);
	else
	{
		waitpid(0, &status, 0);
		if (WIFEXITED(status))
			return (status);
	}
	return (0);
}
