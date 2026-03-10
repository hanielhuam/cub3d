/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:01:09 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/09 18:30:21 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*temp;
	size_t	sz;

	if (!s)
		return (NULL);
	sz = ft_strlen(s);
	if (start > sz)
		return (ft_strdup(""));
	if (start + len > sz)
		len = sz - start;
	sub = ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	temp = sub;
	while (len--)
		*sub++ = s[start++];
	*sub = '\0';
	return (temp);
}
/*
#include <stdio.h>

int	main(void)
{
	//test when len is 0 => ""
	printf("%s\n", ft_substr("haniel", 0, 0));
	//test when start is after s lenght => ""
	printf("%s\n", ft_substr("Haniel", 10, 0));
	//test when start + len is gtrater then lenght of s => all word
	printf("%s\n", ft_substr("Haniel", 0, 10));
	//test when its everything ok => subeord
	printf("%s\n", ft_substr("Haniel", 1, 3));
	return (0);
}*/
