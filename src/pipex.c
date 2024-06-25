/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:43:49 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/25 16:45:52 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	parent_process(int pipe_fd[], char *argv[], char *envp[]);
static void	child_process(int pipe_fd[], char *argv[], char *envp[]);
static void	create_forks(int pipe_fd[], char *argv[], char *envp[]);
static void	execute_command(char *cmd_str, char *envp[]);

int	main(int argc, char *argv[], char *envp[])
{
	int		pipe_fd[2];

	if (argc != 5)
		return (
			ft_printf("Usage: %s infile \"cmd1\" \"cmd2\" outfile\n", argv[0]),
			EXIT_FAILURE
		);
	if (pipe(pipe_fd) == -1)
		error_handler("Pipe creation failed", EXIT_FAILURE);
	create_forks(pipe_fd, argv, envp);
	return (EXIT_SUCCESS);
}

static void	create_forks(int pipe_fd[], char *argv[], char *envp[])
{
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	pid1 = fork();
	if (pid1 == -1)
		error_handler("Child fork failed", EXIT_FAILURE);
	else if (pid1 == 0)
		child_process(pipe_fd, argv, envp);
	else
	{
		pid2 = fork();
		if (pid2 == -1)
			error_handler("Parent fork failed", EXIT_FAILURE);
		else if (pid2 == 0)
			parent_process(pipe_fd, argv, envp);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, &status, 0);
		if (WIFEXITED(status))
			exit(WEXITSTATUS(status));
	}
}

static void	execute_command(char *cmd_str, char *envp[])
{
	char	**cmd_args;
	char	*cmd_path;

	cmd_args = ft_split(cmd_str, ' ');
	if (!cmd_args)
		exit(EXIT_FAILURE);
	cmd_path = find_executable_path(cmd_args[0], envp);
	if (!cmd_path)
	{
		free_array((void *)cmd_args);
		error_handler("Command not found", EXIT_COMMAND_NOT_FOUND);
	}
	if (execve(cmd_path, cmd_args, envp) == -1)
	{
		free(cmd_path);
		free_array((void *)cmd_args);
		error_handler("Execution of command failed", EXIT_FAILURE);
	}
	free(cmd_path);
	free_array((void *)cmd_args);
	error_handler("Execution of command failed", EXIT_FAILURE);
}

static void	parent_process(int pipe_fd[], char *argv[], char *envp[])
{
	int	fd;

	close(pipe_fd[1]);
	fd = open_file(argv[4], STDOUT_FILENO);
	if (fd == -1)
		error_handler("Failed to open output file", EXIT_FAILURE);
	if (dup2(fd, STDOUT_FILENO) == -1)
		error_handler("dup2 (parent to file) failed", EXIT_FAILURE);
	close(fd);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		error_handler("dup2 (parent to pipe) failed", EXIT_FAILURE);
	close(pipe_fd[0]);
	execute_command(argv[3], envp);
}

static void	child_process(int pipe_fd[], char *argv[], char *envp[])
{
	int	fd;

	close(pipe_fd[0]);
	fd = open_file(argv[1], STDIN_FILENO);
	if (fd == -1)
		error_handler("Failed to open input file", EXIT_FAILURE);
	if (dup2(fd, STDIN_FILENO) == -1)
		error_handler("dup2 (child from file) failed", EXIT_FAILURE);
	close(fd);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		error_handler("dup2 (child to pipe) failed", EXIT_FAILURE);
	close(pipe_fd[1]);
	execute_command(argv[2], envp);
}
