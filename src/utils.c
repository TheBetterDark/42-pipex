/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:53:22 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/25 16:45:47 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error_handler(char *info, int exit_code)
{
	perror(info);
	exit(exit_code);
}

int	open_file(char *file_path, int io_stream)
{
	int	fd;

	if (io_stream == STDIN_FILENO)
		fd = open(file_path, O_RDONLY, 0644);
	else if (io_stream == STDOUT_FILENO)
		fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = -1;
	if (fd == -1)
		return (-1);
	return (fd);
}

char	*find_executable_path(char *exec_name, char *envp[])
{
	char	**path_directories;
	char	*partial_path;
	char	*path;
	int		i;

	path_directories = get_environmental_variables(envp);
	if (!path_directories)
		exit(EXIT_FAILURE);
	i = 0;
	while (path_directories[i])
	{
		partial_path = ft_strjoin(path_directories[i], "/");
		if (!partial_path)
			return (free_array((void *)path_directories), NULL);
		path = ft_strjoin(partial_path, exec_name);
		free(partial_path);
		if (!path)
			return (free_array((void *)path_directories), NULL);
		if (access(path, F_OK | X_OK) == 0)
			return (free_array((void *)path_directories), path);
		free(path);
		i++;
	}
	return (free_array((void *)path_directories), NULL);
}

char	**get_environmental_variables(char *envp[])
{
	int	i;

	if (!envp)
		return (NULL);
	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	return (ft_split(envp[i] + 5, ':'));
}

void	free_array(void **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
