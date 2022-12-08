/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:11:21 by creyt             #+#    #+#             */
/*   Updated: 2022/12/06 16:15:34 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != c)
	{
		if (str[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return ((char *)str + i);
}

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*src;
	char	*dst;
	size_t	count;

	dst = malloc(len + 1);
	if (!dst)
	{
		return (0);
	}
	if (dst == 0)
		return (0);
	src = (char *)str + start;
	count = 0;
	while (*src && count < len)
	{
		dst[count] = *src;
		src++;
		count++;
	}
	dst[count] = '\0';
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(const char *str1, const char *str2)
{
	size_t	stock;
	size_t	len;
	char	*res;

	len = ft_strlen(str1) + ft_strlen(str2);
	res = malloc(len + 1);
	if (!res)
		return (0);
	stock = 0;
	while (*str1)
	{
		res[stock] = *str1;
		stock++;
		str1++;
	}
	while (*str2)
	{
		res[stock] = *str2;
		stock++;
		str2++;
	}
	res[stock] = '\0';
	return (res);
}

/*
void	*gnl_bzero(void *s, size_t n)
{
	int	is;

	is = 0;
	while (n-- > 0)
		((char *)s)[is++] = '\0';
	return (s);
}

size_t	gnl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strjoin(char **s1, char const *s2)
{
	char	*res;
	int		i1;
	int		i2;
	int		ires;

	ires = 0;
	if (s2 == NULL)
		return (NULL);
	res = malloc((gnl_strlen(*s1) + (gnl_strlen(s2) + 1)) * sizeof(char));
	if (! res)
		return (NULL);
	gnl_bzero(res, ((gnl_strlen(*s1) + gnl_strlen(s2) + 1) * sizeof(char)));
	i1 = 0;
	while ((*s1)[i1] != '\0')
		res[ires++] = (*s1)[i1++];
	i2 = 0;
	while (s2[i2] != '\0')
		res[ires++] = s2[i2++];
	res[ires] = '\0';
	free(*s1);
	return (res);
}

char	*gnl_strdup(char **s1, int istr)
{
	char	*copy;
	int		icopy;

	icopy = 0;
	copy = malloc((gnl_strlen(*s1) + 1) * sizeof(char));
	if (! copy)
		return (NULL);
	gnl_bzero(copy, (gnl_strlen(*s1) + 1) * sizeof(char));
	while ((*s1)[istr] != '\0')
		copy[icopy++] = (*s1)[istr++];
	copy[icopy] = '\0';
	free(*s1);
	return (copy);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	isub;

	isub = 0;
	if (s == NULL)
		return (NULL);
	if (start > gnl_strlen(s))
		return (NULL);
	if ((gnl_strlen(s) - start) < len)
		substr = malloc((gnl_strlen(s) - start + 1) * sizeof(char));
	else
		substr = malloc((len + 1) * sizeof(char));
	if (! substr)
		return (NULL);
	while (isub < len && s[start] != '\0')
		substr[isub++] = s[start++];
	substr[isub] = '\0';
	return (substr);
}
*/
