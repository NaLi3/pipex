/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:34:35 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/21 02:00:39 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/h_files/ft_pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		i;
	int		filein_fd;
	int		fileout_fd;

	ft_check_arg_bonus(argc);
	if (argc < 5)
		return (1);
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		i = 3;
		fileout_fd = ft_open_file(argv[argc - 1], 2);
		ft_here_doc(argv, fileout_fd);
	}
	else
	{
		i = 2;
		fileout_fd = ft_open_file(argv[argc - 1], 1);
		filein_fd = ft_open_file(argv[1], 0);
		dup2(filein_fd, STDIN_FILENO);
	}
	while (i < argc - 2)
		ft_child(argv[i++], env);
	dup2(fileout_fd, STDOUT_FILENO);
	ft_exec(argv[argc - 2], env);
}
