/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:02:08 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/21 16:17:37 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include "libft.h"
# include "ft_get_next_line.h"
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>

// Folder: Obligatory

// File: ft_children.c
void	ft_darius(char **argv, int *pipe_fd, char **env);
void	ft_draven(char **argv, int *pipe_fd, char **env);
void	ft_pipe_failed(void);
void	ft_fork_failed(void);
char	*ft_check_specific_path(char *cmd);

// File : ft_utils.c
void	ft_exec(char *cmd, char **env);
char	*ft_get_env(char *path, char **env);
char	*ft_get_path(char *cmd, char **env);
int		ft_open_file(char *filename, int option);
void	ft_check_arg(int argc);

//End of Folder: Obligatory

// Folder: Bonus

// File: ft_utils_bonus.c
void	ft_check_arg_bonus(int argc);
void	ft_pipe_failed_bonus(void);
void	ft_fork_failed_bonus(void);

// File: ft_children_bonus.c
void	ft_child(char *argv, char **env);
void	ft_here_doc(char **argv, int fileout_fd);
char	*ft_get_next_line(int fd, char *limiter);

#endif
