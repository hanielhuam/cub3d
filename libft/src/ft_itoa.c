/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:17:58 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/26 07:53:24 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	if (n < 0)
		i++;
	while (n && ++i)
		n /= 10;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		size;
	long	nb;

	size = count_digits(n);
	nbr = ft_calloc(size + 1, sizeof(char));
	if (!n)
	{
		nbr[0] = '0';
		return (nbr);
	}
	nb = (long)n;
	if (nb < 0)
	{
		nb = -nb;
		nbr[0] = '-';
	}
	while (nb)
	{
		nbr[--size] = nb % 10 + '0';
		nb /= 10;
	}
	return (nbr);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", count_digits(0));
	printf("%s\n", ft_itoa(0));
	return (0);
}
*/
