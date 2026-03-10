/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:29:23 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/26 07:13:31 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *) s;
	while (n--)
		*temp++ = c;
	return (s);
}
/*
#include <string.h>
#include <stdio.h>

size_t	evaluate(char *s, int c, size_t size);

//TODO substitute strcpy for ft_strcpy
int	main(void)
{
	char	*example = "example";
	char	*s;
	size_t	size;
	
	size = ft_strlen(example);
	s = malloc(sizeof(char) * size);
	strncpy(s, example, size);
	ft_memset(s, 0, size);
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
