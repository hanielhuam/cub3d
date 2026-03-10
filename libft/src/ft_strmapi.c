/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:17:53 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/26 07:54:11 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	size;
	unsigned int	i;
	char			*ptr;

	size = (unsigned int) ft_strlen(s);
	ptr = ft_calloc(size + 1, sizeof(char));
	i = 0;
	while (i < size)
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	return (ptr);
}
/*
#include <stdio.h>

char	addme(unsigned int i, char c)
{
	return (c + i);
}

int	main (void)
{
	printf("%s\n", ft_strmapi("12345", addme));
	return (0);
}*/
