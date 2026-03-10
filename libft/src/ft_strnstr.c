/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 09:51:16 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/27 11:46:07 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_sz;
	size_t	i;

	if (!*little)
		return ((char *) big);
	little_sz = ft_strlen(little);
	if (len < little_sz)
		return (NULL);
	i = 0;
	while (big[i] && i <= len - little_sz)
	{
		if (!ft_strncmp(&big[i], little, little_sz))
			return ((char *) &big[i]);
		i++;
	}
	return (NULL);
}
/*
#include <bsd/string.h>
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strnstr("aaabcabcd", "cd", 8));
	printf("%s\n", strnstr("aaabcabcd", "cd", 8));
	return (0);
}*/
