/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:59:57 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/11/08 21:20:10 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	if (!s || !*s)
		return (count);
	if (*s != c)
	{
		count++;
		s++;
	}
	while (*s)
	{
		if (*s != c && *(s - 1) == c)
			count++;
		s++;
	}
	return (count);
}

static size_t	end_word(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static const char	*make_line(char **line, const char *s, char c)
{
	size_t	end;

	end = end_word(s, c);
	*line = ft_substr(s, 0, end);
	if (!line)
		return (NULL);
	s += end;
	return (s);
}

static void	make_matrix(char **matrix, const char *s, char c, size_t sz)
{
	size_t	i;

	i = 0;
	if (!s || !*s)
		return ;
	if (*s != c)
	{
		s = make_line(&matrix[i], s, c);
		if (!s)
			return ;
		i++;
	}
	while (i < sz && *s)
	{
		if (*s != c && *(s - 1) == c)
		{
			s = make_line(&matrix[i], s, c);
			if (!s)
				return ;
			i++;
		}
		else
			s++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		sz;
	char		**matrix;

	if (!s)
		return (NULL);
	sz = count_words(s, c);
	matrix = (char **) ft_calloc((sz + 1), sizeof(char *));
	if (!matrix)
		return (NULL);
	make_matrix(matrix, s, c, sz);
	i = 0;
	while (matrix[i])
		i++;
	if (i < sz)
	{
		while (i)
			free(matrix[i--]);
		free(matrix[0]);
		matrix[0] = NULL;
	}
	return (matrix);
}
/*
#include <stdio.h>

void	show(char **matrix, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		printf("%s\n", matrix[i++]);
}

int	main(void)
{
	show(ft_split(" Haniel Huam Macedo Ferreira", ' '), 5);
	return (0);
}*/
