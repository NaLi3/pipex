/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:35:31 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/21 14:51:57 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/h_files/ft_pipex.h"

void	ft_check_arg_bonus(int argc);
void	ft_pipe_failed_bonus(void);
void	ft_fork_failed_bonus(void);

void	ft_check_arg_bonus(int argc)
{
	if (argc < 5)
	{
		ft_printf(2, "pipex_bonus: %s\n", strerror(EINVAL));
		ft_putendl_fd("./pipex_bonus [File1] [cmd1] [cmd2] [..] [File2]", 2);
		ft_putstr_fd("./pipex_bonus \"here_doc\" [LIMITER]", 2);
		ft_putendl_fd(" [cmd1] [cmd2] [...] [outfile]", 2);
		exit(22);
	}
}

void	ft_pipe_failed_bonus(void)
{
	ft_printf(2, "pipex_bonus: fork failed: Resource temporarily unavailable");
	ft_printf(2, "\n");
	exit(132);
}

void	ft_fork_failed_bonus(void)
{
	ft_printf(2, "pipex_bonus: %s\n", strerror(EPIPE));
	exit(32);
}
