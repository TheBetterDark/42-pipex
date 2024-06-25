/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:38:59 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/23 14:39:47 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// Standard C libaries

# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

// Marco definitions

# define EXIT_COMMAND_NOT_FOUND 127

// Related libaries

# include "../libs/libft/includes/libft.h"

// Function declerations

char	*find_executable_path(char *exec_name, char *envp[]);
char	**get_environmental_variables(char *envp[]);
int		open_file(char *file_path, int io_stream);
void	error_handler(char *info, int exit_code);
void	free_array(void **array);

#endif
