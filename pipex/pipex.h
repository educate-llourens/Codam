/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/11 17:53:31 by llourens      #+#    #+#                 */
/*   Updated: 2025/03/06 19:31:49 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../printf/ft_printf.h"
# include "../printf/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> 
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int		pipe_read;
	int		pipe_write;
	int		fd_input_file;
	int		fd_output_file;
	char	*cmd1;
	char	*cmd2;
	char	**environment;
}				t_pipex;

/* Error handling */
void	perror_and_exit(char *message);
void	free_split(char **split);

/* Utils*/
void	input_checks(t_pipex *pipe_data, int argc, char **argv, char **env);
char	*get_cmd_path(char *cmd, char **env);
char	*ft_get_env(char **envp);

/* Src | Files and cmd*/
void	input_and_cmd1(t_pipex pipe_data, char *orig_cmd1);
void	output_and_cmd2(t_pipex pipe_data, char *orig_cmd2);

/* Struct*/
void	populate_pipe_data(t_pipex *pipe_data, int fd_pipe[2],
			char **argv, char **env);

#endif