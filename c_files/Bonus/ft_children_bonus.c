/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_children_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:35:22 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/21 14:53:15 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/h_files/ft_pipex.h"

void		ft_child(char *cmd, char **env);
void		ft_here_doc(char **argv, int fileout_fd);
static void	ft_put_here_doc(char **argv, int *fd, int fileout_fd);
char		*ft_get_next_line(int fd, char *limiter);

void	ft_child(char *cmd, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_pipe_failed_bonus();
	pid = fork();
	if (pid == -1)
		ft_fork_failed_bonus();
	if (!pid)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		ft_exec(cmd, env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	ft_here_doc(char **argv, int fileout_fd)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_pipe_failed_bonus();
	pid = fork();
	if (pid == -1)
		ft_fork_failed_bonus();
	if (!pid)
		ft_put_here_doc(argv, fd, fileout_fd);
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		wait(NULL);
	}
}

static void	ft_put_here_doc(char **argv, int *fd, int fileout_fd)
{
	char	*line;

	close(fd[0]);
	while (1)
	{
		line = ft_get_next_line(0, argv[2]);
		if (!ft_strncmp(line, argv[2], ft_strlen(argv[2])))
		{
			close(fd[0]);
			close(fd[1]);
			close(fileout_fd);
			free(line);
			exit(0);
		}
		ft_putstr_fd(line, fd[1]);
		free(line);
	}
}

char	*ft_get_next_line(int fd, char *limiter)
{
	static char	*buffer[256];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 256)
		return (NULL);
	buffer[fd] = get_read_file(fd, &buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = gt_line(buffer[fd]);
	buffer[fd] = get_next(buffer[fd]);
	if (!strncmp(line, limiter, ft_strlen(limiter)))
		free(buffer[fd]);
	return (line);
}
