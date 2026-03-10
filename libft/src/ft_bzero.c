/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:39:10 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/26 08:06:38 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	return (ft_memset(s, 0, n));
}
/*
#include <string.h>
#include <stdio.h>

size_t	evaluate(char *s, int c, size_t size);

int	main(void)
{
	char	*example = "example";
	char	*s;
	size_t	size;
	
	size = ft_strlen(example);
	s = malloc(sizeof(char) * size);
	strncpy(s, example, size);
	ft_bzero(s, size);
	printf("size: %zu and evaluation: %zu\n", size, evaluate(s, 0, size));
	free(s);
	return (0);
}

size_t	evaluate(char *s, int c, size_t size)
{
	size_t	i;

	i = 0;
	while (s[i] == c && i < size)
		printf("%c\n", s[i++]);
	return (i);
}*/
