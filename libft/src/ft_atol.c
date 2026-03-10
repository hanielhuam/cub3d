/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:32:59 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/04/23 17:13:56 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	char	signal;
	long	result;

	while (ft_isspace(*nptr))
		nptr++;
	signal = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr++ == '-')
			signal = -1;
	}
	result = 0;
	while (ft_isdigit(*nptr))
		result = result * 10 + (*nptr++ - '0');
	return (result * signal);
}
/*
#include <stdlib.h>
#include <stdio.h>
int	main(void)
{
	printf("%ld\n", ft_atol("   -44234"));
	//printf("%ld\n", atol("44"));
	return (0);
}*/
