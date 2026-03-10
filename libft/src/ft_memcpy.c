/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:19:49 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/26 17:55:48 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dtemp;
	unsigned char	*stemp;

	dtemp = (unsigned char *) dest;
	stemp = (unsigned char *) src;
	while (n--)
		*dtemp++ = *stemp++;
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>

size_t	evaluate(char *dest, char *src, size_t size);

int	main(void)
{
	char	*example = "example";
	char	*s;
	char	*d;
	size_t	size;
	
	size = ft_strlen(example);
	s = malloc(sizeof(char) * size);
	d = malloc(sizeof(char) * (size + 1));
	strncpy(s, example, size);
	ft_memcpy(d, s, size);
	printf("size: %zu and evaluation: %zu\n", size, evaluate(d, s, size));
	free(s);
	return (0);
}

size_t	evaluate(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (dest[i] == src[i] && i < size)
		printf("%c\n", src[i++]);
	return (i);
}*/
