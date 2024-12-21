/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:31:43 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/21 16:29:32 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/h_files/ft_pipex.h"

// Functions in this file.
void	ft_exec(char *cmd, char **env);
char	*ft_get_env(char *path, char **env);
char	*ft_get_path(char *cmd, char **env);
int		ft_open_file(char *filename, int option);
void	ft_check_arg(int argc);

void	ft_exec(char *cmd, char **env)
{
	char	**t_cmd;
	char	*path;
	int		i;

	t_cmd = ft_split(cmd, ' ');
	if (!t_cmd || !t_cmd[0] || !env || !env[0])
		path = NULL;
	else
		path = ft_get_path(t_cmd[0], env);
	ft_printf(2, "this is t_cmd[0] %s\n", t_cmd[0]);
	ft_printf(2, "this is path %s\n", path);
	i = execve(path, t_cmd, env);
	if (i == -1)
	{
		ft_printf(2,"pipex: command not found: %s\n", t_cmd[0]);
		ft_free_tab_void(t_cmd);
		exit(127);
	}
}

char	*ft_get_env(char *path, char **env)
{
	int		x;
	int		y;
	char	*temp;

	x = 0;
	while (env[x])
	{
		y = 0;
		while (env[x][y] && env[x][y] != '=')
			y++;
		temp = ft_substr(env[x], 0, y);
		if (!ft_strncmp(temp, path, y))
		{
			free(temp);
			return (&env[x][y + 1]);
		}
		free(temp);
		x++;
	}
	return (NULL);
}

char	*ft_get_path(char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	**fullpath;
	char	*part;
	char	**t_cmd;

	if (ft_check_specific_path(cmd))
		return (ft_check_specific_path(cmd));
	i = -1;
	fullpath = ft_split(ft_get_env("PATH", env), ':');
	t_cmd = ft_split(cmd, ' ');
	while (fullpath[++i])
	{
		part = ft_strjoin(fullpath[i], "/");
		exec = ft_strjoin(part, t_cmd[0]);
		free(part);
		if (!access(exec, F_OK | X_OK))
		{
			ft_free_tab_void(t_cmd);
			return (exec);
		}
		free(exec);
	}
	ft_free_tab_void(fullpath);
	ft_free_tab_void(t_cmd);
	return (NULL);
}

int	ft_open_file(char *filename, int option)
{
	int		fd;

	fd = open(filename, O_RDONLY, 0644);
	if (!option)
		fd = open(filename, O_RDONLY, 0644);
	else if (option == 1)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (option == 2)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		ft_printf(2, "pipex: %s: %s\n", strerror(ENOENT), filename);
		exit(2);
	}
	return (fd);
}

void	ft_check_arg(int argc)
{
	if (argc != 5)
	{
		ft_printf(2, "pipex: %s\n", strerror(EINVAL));
		ft_putendl_fd("Usage: ./pipex [infile] [cmd1] [cmd2] [outfile]", 2);
		exit(22);
	}
}
