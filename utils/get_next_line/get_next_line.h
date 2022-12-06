/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:10:03 by creyt             #+#    #+#             */
/*   Updated: 2022/03/03 11:33:21 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include "get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*line_return(char **str, int i);
char	*no_read(char **str);
char	*buffer_not_empty(char **str, int i);
char	*read_loop(int fd, char **str);
void	*gnl_bzero(void *s, size_t n);
size_t	gnl_strlen(const char *str);
char	*gnl_strjoin(char **s1, char const *s2);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
char	*gnl_strdup(char **s1, int istr);

#endif
