/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:30:25 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/21 14:48:42 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/h_files/ft_pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		pipe_fd[2];
	int		status[2];
	pid_t	pid[2];

	ft_check_arg(argc);
	if (pipe(pipe_fd) == -1)
		ft_pipe_failed();
	pid[0] = fork();
	if (pid[0] == -1)
		ft_fork_failed();
	if (pid[0] == 0)
		ft_darius(argv, pipe_fd, env);
	close(pipe_fd[1]);
	pid[1] = fork();
	if (pid[1] == -1)
		ft_fork_failed();
	if (pid[1] == 0)
		ft_draven(argv, pipe_fd, env);
	close(pipe_fd[0]);
	waitpid(pid[0], &status[0], 0);
	waitpid(pid[1], &status[1], 0);
	if (!status[0] && !status[1])
		return (0);
	return (1);
}
