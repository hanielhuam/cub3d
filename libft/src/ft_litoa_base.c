/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:10:25 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/12/09 19:30:16 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long int n, int base_lenght)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	if (n < 0)
		i++;
	while (n && ++i)
		n /= base_lenght;
	return (i);
}

static int	verify_base(char *str)
{
	char	*deny;
	int		i;
	int		lenght;

	i = 0;
	while (str[i])
		i++;
	lenght = i;
	i = 0;
	while (str[i])
	{
		if (ft_strchr(&str[i + 1], str[i]))
			return (0);
		i++;
	}
	deny = "+-";
	i = 0;
	while (deny[i])
	{
		if (ft_strchr(str, deny[i]))
			return (0);
		i++;
	}
	return (lenght);
}

static void	treat_negative(long int *n, char *nbr, char *base)
{
	if (!*n)
		nbr[0] = base[0];
	if (*n < 0)
	{
		*n = -*n;
		nbr[0] = '-';
	}
}

char	*ft_litoa_base(long int n, char *base)
{
	int		base_lenght;
	char	*nbr;
	int		size;

	base_lenght = verify_base(base);
	if (base_lenght <= 1)
		return (NULL);
	size = count_digits(n, base_lenght);
	nbr = ft_calloc(size + 1, sizeof(char));
	if (!nbr)
		return (NULL);
	if (n == LONG_MIN)
	{
		nbr[0] = '-';
		nbr[--size] = base[n % base_lenght * (-1)];
		n = n / base_lenght * (-1);
	}
	treat_negative(&n, nbr, base);
	while (n)
	{
		nbr[--size] = base[n % base_lenght];
		n /= base_lenght;
	}
	return (nbr);
}
/*
#include <stdio.h>

int    main(int argc, char **argv)
{
    if (argc != 3)
        return (0);
    printf("%s", ft_litoa_base(ULONG_MAX, argv[2]));
    return (0);
}*/
