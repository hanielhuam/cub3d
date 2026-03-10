/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:22:48 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/08 20:00:36 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	sz;
	char	*sdup;

	sz = ft_strlen(s) + 1;
	sdup = malloc(sizeof(char) * sz);
	if (!sdup)
		return (NULL);
	while (*s)
		*sdup++ = *s++;
	*sdup = *s;
	return (sdup -= sz - 1);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	*s = "haniel";

	printf("%s\n", ft_strdup(s));
	printf("%s\n", strdup(s));
	return (0);
}*/
