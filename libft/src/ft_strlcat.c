/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:30:20 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/09 20:34:06 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (size <= 0)
		return (ft_strlen(src));
	i = 0;
	while (dst[i] && i < size)
		i++;
	j = 0;
	while (src[j] && (i + j) < size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
/*
#include <bsd/string.h>
#include <stdio.h>

void	evaluate(char *dest, char *src);

int	main(void)
{
	char	*example = "examplesssssssss";
	char	*s;
	char	*d;
	size_t	size;
	
	size = ft_strlen(example) + 1;
	s = ft_strdup(example);
	d = ft_calloc((size - 9), sizeof(char));
	ft_bzero(d, size - 9);
	ft_strlcpy(d, "Haniel", size -9);
	evaluate(d, s);
	printf("%zu\n", ft_strlcat(d, s, 12));
	//printf("%zu\n", strlcat(d, s, 6));
	evaluate(d, s);
	free(s);
	free(d);
	return (0);
}

void	evaluate(char *dest, char *src)
{
	size_t	i;

	printf("dest:\n");
	i = 0;
	while (dest[i])
		printf("%c", dest[i++]);
	printf("\nsrc:\n");
	i = 0;
	while (src[i])
		printf("%c", src[i++]);
	printf("\n");
}*/
