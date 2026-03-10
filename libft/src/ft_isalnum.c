/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:39:00 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/09/23 19:50:25 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%d", ft_isalnum('a'));
	printf("%d", ft_isalnum('z'));
	printf("%d", ft_isalnum('A'));
	printf("%d", ft_isalnum('Z'));
	printf("%d", ft_isalnum('0'));
	printf("%d", ft_isalnum('9'));
	printf("%d", ft_isalnum('3'));
	printf("%d", ft_isalnum('?'));
	printf("%d", ft_isalnum('\n'));
	return (0);
}*/
