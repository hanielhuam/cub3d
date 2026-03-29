/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 21:09:54 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/03/23 21:42:41 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	int 	fd;
	char	*result;

	(void)argc;
	(void)argv;
	fd = open("test", O_RDWR);
	ft_printf("testando o %s\n", argv[0]);
	ft_dprintf(fd, "vou gravar o nome da %s em outro arquivo\n", argv[0]);
	result = str_format("vou criar %s \n", "sapo");
	write(1, result, ft_strlen(result));
	close(fd);
	return (0);
}
