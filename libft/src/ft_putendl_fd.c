/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 22:00:32 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/19 19:32:39 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/*
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("testc.txt", O_WRONLY);
	ft_putendl_fd("Haniel", fd);
	ft_putendl_fd("Huam", fd);
	ft_putendl_fd("Macedo", fd);
	ft_putendl_fd("Ferreira", fd);
	close(fd);
}*/
