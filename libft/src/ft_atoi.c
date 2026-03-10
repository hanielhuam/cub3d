/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:45:13 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/04/23 17:12:48 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	char	signal;
	int		result;

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
	printf("%d\n", ft_atoi("\n\f-199a4"));
	printf("%d\n", atoi("\n\f-199a4"));
	return (0);
}*/
