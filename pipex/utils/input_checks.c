/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/15 20:19:01 by root          #+#    #+#                 */
/*   Updated: 2025/10/24 10:13:31 by lelouren      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	input_checks(t_pipex *pipe_data, int argc, char **argv, char **env)
{
	if (argc < 5)
		perror_and_exit("Incorrect number of arguments. Usage: ./pipex file1 cmd1 cmd2 file2");
	pipe_data->fd_output_file = open(argv[4],
			O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (argc > 5 && argc != 2)
		perror_and_exit("Incorrect number of arguments. Usage: ./pipex file1 cmd1 cmd2 file2");
	if ((access(argv[1], F_OK) != 0) || (access(argv[4], F_OK) != 0))
		perror_and_exit("file not found");
	if (access(argv[1], R_OK) != 0)
		perror_and_exit("infile");
	if ((access(argv[4], W_OK) != 0) || (access(".", W_OK) != 0))
		perror_and_exit("outfile");
	if (!env)
		perror_and_exit("env is NULL");
	while (*argv != NULL)
	{
		if (**argv == '\0')
		{
			ft_putendl_fd("empty string", STDERR_FILENO);
			exit (1);
		}
		argv++;
	}
}
