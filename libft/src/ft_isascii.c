/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:51:28 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/09/23 19:59:38 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d", ft_isascii('a'));
	printf("%d", ft_isascii('z'));
	printf("%d", ft_isascii('A'));
	printf("%d", ft_isascii('Z'));
	printf("%d", ft_isascii('0'));
	printf("%d", ft_isascii('9'));
	printf("%d", ft_isascii('3'));
	printf("%d", ft_isascii('?'));
	printf("%d", ft_isascii('\n'));
	printf("%d", ft_isascii(0));
	printf("%d", ft_isascii(127));
	printf("%d", ft_isascii(128));
	printf("%d", ft_isascii(-1));
	return (0);
}*/
