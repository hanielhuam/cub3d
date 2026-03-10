/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:27:33 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/28 18:41:58 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*su1;
	unsigned char	*su2;

	if (n < 1)
		return (0);
	su1 = (unsigned char *) s1;
	su2 = (unsigned char *) s2;
	i = 0;
	while (su1[i] == su2[i] && i < n - 1)
		i++;
	return (su1[i] - su2[i]);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_strncmp("test\200", "test\0", 6));
	printf("%d\n", strncmp("test\200", "test\0", 6));
	return (0);
}*/
