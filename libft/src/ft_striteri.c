/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:13:09 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/26 07:55:08 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (*s)
	{
		f(i, s++);
		i++;
	}
}
/*
#include <stdio.h>

void	addme(unsigned int i, char *c)
{
	*c += i;
}

int	main (void)
{
	char	*ptr;

	ptr = ft_strdup("12345");
	printf("%s\n", ptr);
	ft_striteri(ptr, addme);
	printf("%s\n", ptr);
	return (0);
}*/
