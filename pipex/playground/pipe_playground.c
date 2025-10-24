/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipe_playground.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/15 19:47:52 by root          #+#    #+#                 */
/*   Updated: 2025/02/15 20:00:26 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(void)
{
	int		fd[2];
	int		pipe_returns;
	pid_t	pid;
	char	buffer[20];

	pipe_returns = pipe(fd); // returns 0 for success and -1 on failure
	printf("pipe returns: %d\n", pipe_returns);
	pid = fork();
	printf("fork returns: %d\n", pid); // returns pid of parent and child
	if (pid == 0)
	{
		close(fd[0]);
		write(fd[1], "Hello, Pipe!", 13);
		close(fd[1]);
		exit(0);
	}
	else
	{
		close(fd[1]);
		read(fd[0], buffer, 13);
		printf("Received: %s\n", buffer);
		close(fd[0]);
	}
	return (0);
}
