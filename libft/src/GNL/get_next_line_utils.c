/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:17:51 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/05/10 20:55:46 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_line	*creat_t_line(char *str, ssize_t size, char ok)
{
	t_line	*line;

	line = malloc(sizeof(t_line) * 1);
	if (!line)
		return (NULL);
	line->str = str;
	line->size = size;
	line->ok = ok;
	line->next = NULL;
	return (line);
}

int	modify_line(t_line *line, char *buffer, size_t len, char ok)
{
	size_t		count;
	char		*str;

	if (!len)
		return (0);
	count = 0;
	if (line->str)
		len += line->size;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (-1);
	while (count < line->size)
	{
		str[count] = (line->str)[count];
		count++;
	}
	while (count < len)
		str[count++] = *buffer++;
	str[count] = '\0';
	free(line->str);
	line->str = str;
	line->size = len;
	line->ok = ok;
	return (0);
}
