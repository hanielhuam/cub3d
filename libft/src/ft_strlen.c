/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:27:07 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/09/26 20:19:09 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", (int) ft_strlen("asdf"));
	printf("%d\n", (int) ft_strlen(""));
	printf("%d\n", (int) ft_strlen("123456789"));
	printf("%d\n", (int) ft_strlen("0"));
	return (0);
}*/
