/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:03:20 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/09/23 19:20:41 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_isalpha('a'));
	printf("%d\n", ft_isalpha('A'));
	printf("%d\n", ft_isalpha('z'));
	printf("%d\n", ft_isalpha('Z'));
	printf("%d\n", ft_isalpha('b'));
	printf("%d\n", ft_isalpha('B'));
	printf("%d\n", ft_isalpha('1'));
	printf("%d\n", ft_isalpha('\n'));
	return (0);
}*/
