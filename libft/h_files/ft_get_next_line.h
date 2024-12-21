/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:36:39 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/19 13:37:10 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stddef.h>

// get_next_line_bonus.c
char	*get_next_line(int fd);
char	*get_free(char *buffer, char *add);
char	*get_read_file(int fd, char **buffer);
char	*get_next(char *buffer);
char	*gt_line(char *buffer);

// get_next_line_utils_bonus.c
int		get_strlen(char *str);
char	*get_strchr(char *str, int i_c);
char	*get_strjoin(char *src, char *add);
void	get_bzero(void *s, size_t n);
void	*get_calloc(size_t count, size_t size);

#endif
