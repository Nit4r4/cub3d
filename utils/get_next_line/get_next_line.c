/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:15:59 by creyt             #+#    #+#             */
/*   Updated: 2022/12/06 16:15:13 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	get_next(int fd, char *buff, char **fd_line)
{
	int		read_line;
	char	*stock;

	while (!ft_strchr(*fd_line, '\n'))
	{
		read_line = read(fd, buff, BUFFER_SIZE);
		buff[read_line] = '\0';
		if (!*fd_line)
		{
			*fd_line = ft_substr(buff, 0, read_line);
		}
		else if (read_line == 0)
		{
			free(buff);
			return ;
		}
		else
		{
			stock = *fd_line;
			*fd_line = ft_strjoin(*fd_line, buff);
			free(stock);
		}
	}
	free(buff);
}

char	*line(char **fd_line)
{
	int		i;
	int		j;
	char	*ret;
	char	*stock;

	if (!*fd_line)
		return (NULL);
	if (!ft_strchr(*fd_line, '\n'))
	{
		ret = ft_substr(*fd_line, 0, ft_strlen(*fd_line));
		free(*fd_line);
		*fd_line = 0;
		if (ret[0] == '\0')
			free (ret);
		else if (ret[0] != '\0')
			return (ret);
		return (NULL);
	}
	i = ft_strlen(*fd_line);
	j = ft_strlen(ft_strchr(*fd_line, '\n'));
	ret = ft_substr(*fd_line, 0, i - j + 1);
	stock = *fd_line;
	*fd_line = ft_substr(ft_strchr(*fd_line, '\n'), 1, j);
	free(stock);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*fd_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!fd_line)
	{
		fd_line = malloc(sizeof(char) * 1);
		fd_line[0] = '\0';
	}
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	get_next(fd, buffer, &fd_line);
	return (line(&fd_line));
}

/*
char	*return_line(char **save, int i)
{
	char	*res;

	res = gnl_substr(*save, 0, ++i);
	*save = gnl_strdup(&(*save), i);
	return (res);
}

char	*no_read(char **save)
{
	free(*save);
	*save = NULL;
	return (NULL);
}

char	*buffer_not_empty(char **save, int i)
{
	char	*res;

	while ((*save)[i] && (*save)[i] != '\n')
		i++;
	if ((*save)[i] == '\n')
		return (return_line(&(*save), i));
	if ((*save)[i] == '\0')
	{
		res = gnl_substr(*save, 0, ++i);
		free(*save);
		*save = NULL;
		return (res);
	}
	return (NULL);
}

char	*ft_reader(int fd, char **save)
{
	int		i;
	int		ret;
	char	buffer[BUFFER_SIZE + 1];

	i = 0;
	while (1)
	{
		gnl_bzero(buffer, (BUFFER_SIZE + 1) * sizeof(char));
		ret = read(fd, buffer, BUFFER_SIZE);
		*save = gnl_strjoin(&(*save), buffer);
		if (ret > 0)
		{
			while ((*save)[i] && (*save)[i] != '\n')
				i++;
			if ((*save)[i] == '\n')
				return (return_line(&(*save), i));
		}
		else if ((*save)[0] == '\0')
			return (no_read(&(*save)));
		else
			return (buffer_not_empty(&(*save), i));
	}
}

char	*get_next_line(int fd)
{
	static char	*save;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!save)
	{
		save = malloc(1 * sizeof(char));
		gnl_bzero(save, 1 * sizeof(char));
	}
	return (ft_reader(fd, &save));
}

int	main()
{
	int	fd = open("test.txt", O_RDONLY);
	int	i = 10;

	while (i-- > 0)
		printf("%s", get_next_line(fd));
}*/
