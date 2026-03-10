/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_delimiter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:00:53 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/05 19:35:44 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	free(s1);
	if (!result)
		return (NULL);
	return (result);
}

static char	*read_file(int fd, char *rest, char *delimiter)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes;

	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(rest);
			return (NULL);
		}
		buffer[bytes] = '\0';
		rest = ft_strjoin_free(rest, buffer);
		if (ft_strnstr(rest, delimiter, ft_strlen(delimiter)))
			break ;
	}
	return (rest);
}

char	*new_rest(char *rest, char *delimiter)
{
	char	*result;

	result = ft_strnstr(rest, delimiter, ft_strlen(delimiter));
	if (!result)
	{
		free(rest);
		return (NULL);
	}
	result += ft_strlen(delimiter);
	if (!*result)
	{
		free(rest);
		return (NULL);
	}
	result = ft_strdup(result);
	free(rest);
	if (!result)
		return (NULL);
	return (result);
}

char	*next_limit(char *rest, char *delimiter)
{
	char	*result;

	if (!*rest)
		return (NULL);
	result = ft_strnstr(rest, delimiter, ft_strlen(delimiter));
	if (!result)
	{
		result = ft_strdup(rest);
		if (!result)
			return (NULL);
		return (result);
	}
	result = ft_substr(rest, 0, ft_strlen(rest) - ft_strlen(result));
	if (!result)
		return (NULL);
	return (result);
}

char	*get_next_delimiter(int fd, char *delimiter)
{
	static char	*rest[_POSIX_OPEN_MAX];
	char		*result;

	if (!delimiter || !*delimiter)
		return (NULL);
	if (!rest[fd])
	{
		rest[fd] = ft_calloc(1, sizeof(char));
		if (!rest[fd])
			return (NULL);
	}
	rest[fd] = read_file(fd, rest[fd], delimiter);
	if (!rest[fd])
		return (NULL);
	result = next_limit(rest[fd], delimiter);
	rest[fd] = new_rest(rest[fd], delimiter);
	return (result);
}
/*
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test", O_RDONLY);
	line = get_next_delimiter(fd, "\n");
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_delimiter(fd, "\n");
	}
	return (0);
}*/
