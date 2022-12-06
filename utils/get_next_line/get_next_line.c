/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:15:59 by creyt             #+#    #+#             */
/*   Updated: 2022/03/03 11:33:06 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

/*int	main()
{
	int	fd = open("test.txt", O_RDONLY);
	int	i = 10;

	while (i-- > 0)
		printf("%s", get_next_line(fd));
}*/
