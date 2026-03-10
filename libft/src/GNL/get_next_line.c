/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:46:34 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/05/10 20:55:17 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*verify_line(t_line **line)
{
	t_line	*temp;
	char	*l;

	l = NULL;
	temp = *line;
	if (temp->ok)
	{
		l = temp->str;
		*line = temp->next;
		free(temp);
	}
	return (l);
}

int	create_line(t_line **line, char *buffer, size_t len, char ok)
{
	t_line	*temp;

	if (modify_line(*line, buffer, len, ok))
		return (-1);
	temp = creat_t_line(NULL, 0, 0);
	if (!temp)
		return (-1);
	(*line)->next = temp;
	*line = temp;
	return (0);
}

int	put_new_line(t_line *line, char *buffer, size_t len)
{
	unsigned int	i;
	unsigned int	init;

	init = 0;
	i = 0;
	while (i < len)
	{
		if (buffer[i] == '\n')
		{
			if (create_line(&line, &buffer[init], i - init + 1, 1))
				return (-1);
			init = i + 1;
		}
		i++;
	}
	if (!line->ok)
	{
		if (modify_line(line, &buffer[init], i - init, 0))
			return (-1);
	}
	return (0);
}

int	read_file(t_line *line, int fd)
{
	char	*buffer;
	ssize_t	lenght;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (-1);
	while (!line->ok)
	{
		lenght = read(fd, buffer, BUFFER_SIZE);
		if (lenght <= 0)
		{
			free(buffer);
			if (lenght < 0)
				return (-1);
			line->ok = 1;
			return (0);
		}
		if (put_new_line(line, buffer, (size_t) lenght))
		{
			free(buffer);
			return (-1);
		}
	}
	free(buffer);
	return (0);
}

char	*get_next_line(int fd)
{
	static t_line	*line[1024];
	char			*l;
	t_line			*temp;

	if (!line[fd])
	{
		line[fd] = creat_t_line(NULL, 0, 0);
		if (!line[fd])
			return (NULL);
	}
	l = verify_line(&line[fd]);
	if (l)
		return (l);
	if (read_file(line[fd], fd))
		return (NULL);
	if (!line[fd])
		return (NULL);
	l = line[fd]->str;
	temp = line[fd];
	line[fd] = line[fd]->next;
	free(temp);
	return (l);
}

/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*str;

	fd1 = open("teste1.txt", O_RDONLY);
	fd2 = open("teste2.txt", O_RDONLY);
	fd3 = open("teste3.txt", O_RDONLY);
	
	str = get_next_line(fd1);
	printf("%s", str);
	free(str);
	
	str = get_next_line(fd2);
	printf("%s", str);
	free(str);
	
	str = get_next_line(fd1);
	printf("%s", str);
	free(str);
	
	str = get_next_line(fd3);
	printf("%s", str);
	free(str);
	
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/
