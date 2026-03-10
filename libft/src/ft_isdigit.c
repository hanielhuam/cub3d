/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:20:10 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/09/23 19:22:43 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d", ft_isdigit('a'));
	printf("%d", ft_isdigit('z'));
	printf("%d", ft_isdigit('A'));
	printf("%d", ft_isdigit('Z'));
	printf("%d", ft_isdigit('0'));
	printf("%d", ft_isdigit('9'));
	printf("%d", ft_isdigit('3'));
	printf("%d", ft_isdigit('?'));
	printf("%d", ft_isdigit('\n'));
	return (0);
}*/
