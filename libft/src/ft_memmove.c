/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:14:14 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/26 17:56:42 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dtemp;
	unsigned char	*stemp;

	if (src < dest)
	{
		dtemp = (unsigned char *) dest;
		stemp = (unsigned char *) src;
		while (n--)
			dtemp[n] = stemp[n];
		return (dest);
	}
	return (ft_memcpy(dest, src, n));
}
/*
#include <string.h>
#include <stdio.h>

void	evaluate(char *dest, char *src, size_t size);

int	main(void)
{
	char s[] = {65, 66, 67, 68, 69, 0, 45};
	char s0[] = { 0,  0,  0,  0,  0,  0, 0};
	
	evaluate(s0, s, 7);
	if (ft_memmove(s0, s, 7) == s0)
		printf("deu certo");
	evaluate(s, s, 7);
	return (0);
}

void	evaluate(char *dest, char *src, size_t size)
{
	size_t	i;

	printf("dest:\n");
	i = 0;
	while (i < size)
		printf("%c", dest[i++]);
	printf("\nsrc:\n");
	i = 0;
	while (i < size)
		printf("%c", src[i++]);
	printf("\n");
}*/
