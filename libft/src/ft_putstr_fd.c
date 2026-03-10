/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:44:22 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/18 22:02:22 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		ft_putchar_fd(*s++, fd);
}
/*
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("testc.txt", O_WRONLY);
	ft_putstr_fd("Haniel", fd);
	close(fd);
}*/
