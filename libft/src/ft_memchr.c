/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:43:55 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/27 20:13:03 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	if (n == 0)
		return (NULL);
	temp = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (temp[i] == (unsigned char) c)
			return (&temp[i]);
		i++;
	}
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char example[] = {0, 1, 2 ,3 ,4 ,5};
	char	*s;
	size_t	size;
	
	size = ft_strlen(example) + 1;
	s = malloc(sizeof(char) * size);
	strncpy(s, example, size);
	printf("%s\n", s);
	printf("ft_memchr = %d\n", (char *) ft_memchr(s, 2, 3) == &s[2]);
	printf("memchr = %d\n", (char *) memchr(s, 2, 3) == &s[2] );
	free(s);
	return (0);
}*/
