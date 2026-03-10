/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:48:05 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/26 08:00:10 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		div;
	int		mod;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	div = n / 10;
	mod = n % 10;
	if (!div)
	{
		mod = mod + '0';
		write(fd, &mod, 1);
		return ;
	}
	ft_putnbr_fd(div, fd);
	mod = mod + '0';
	write(fd, &mod, 1);
}
/*
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("testc.txt", O_WRONLY);
	ft_putnbr_fd(789, fd);
	close(fd);
	return (0);
}*/
