/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_children.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:43:42 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/21 16:17:23 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/h_files/ft_pipex.h"

//Functions in this file
void	ft_darius(char **argv, int *pipe_fd, char **env);
void	ft_draven(char **argv, int *pipe_fd, char **env);
void	ft_pipe_failed(void);
void	ft_fork_failed(void);
char	*ft_check_specific_path(char *cmd);

void	ft_darius(char **argv, int *pipe_fd, char **env)
{
	int		fd;

	fd = ft_open_file(argv[1], 0);
	dup2(fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	ft_exec(argv[2], env);
	exit(0);
}

void	ft_draven(char **argv, int *pipe_fd, char **env)
{
	int		fd;

	fd = ft_open_file(argv[4], 1);
	dup2(fd, STDOUT_FILENO);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	ft_exec(argv[3], env);
	exit(0);
}

void	ft_pipe_failed(void)
{
	ft_printf(2, "pipex: fork failed: Resource temporarily unavailable\n");
	exit(132);
}

void	ft_fork_failed(void)
{
	ft_printf(2, "pipex: %s\n", strerror(EPIPE));
	exit(32);
}

char	*ft_check_specific_path(char *cmd)
{
	if (!ft_strncmp(cmd, ".", 1) && (!ft_strncmp(cmd + 1, "/", 1)))
		return (ft_strchr(cmd, '.'));
	else if (ft_strchr(cmd, '/'))
		return (ft_strchr(cmd, '/'));
	return (NULL);
}
