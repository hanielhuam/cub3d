/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:41:35 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/27 11:05:19 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*temp;
	size_t		i;

	if (size > 0)
	{
		temp = src;
		i = 0;
		while (*temp && i < size - 1)
		{
			*dst++ = *temp++;
			i++;
		}
		*dst = '\0';
	}
	return (ft_strlen(src));
}
/*
#include <bsd/string.h>
#include <stdio.h>

void	evaluate(char *dest, char *src);

int	main(void)
{
	char	s[] = "coucou";
	char	d[] = "AAAAAAAAAA";
	
	evaluate(d, s);
	printf("ft_strlcpy = %zu\n", ft_strlcpy(d, s, 2));
	//printf("strlcpy = %zu\n", strlcpy(d, s, 0));
	evaluate(d, s);
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
