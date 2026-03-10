/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:02:27 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/09/23 20:26:08 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d", ft_isprint('a'));
	printf("%d", ft_isprint('z'));
	printf("%d", ft_isprint('A'));
	printf("%d", ft_isprint('Z'));
	printf("%d", ft_isprint('0'));
	printf("%d", ft_isprint('9'));
	printf("%d", ft_isprint('3'));
	printf("%d", ft_isprint('?'));
	printf("%d", ft_isprint(' '));
	printf("%d", ft_isprint('~'));
	printf("%d", ft_isprint('\n'));
	printf("%d", ft_isprint(0));
	printf("%d", ft_isprint(127));
	printf("%d", ft_isprint(128));
	printf("%d", ft_isprint(-1));
	return (0);
}*/
