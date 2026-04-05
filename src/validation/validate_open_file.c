/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_open_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 20:37:32 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/04/05 20:38:30 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	validate_file_type(char *file_name)
{
	char	*file_type;

	file_type = ft_strrchr(file_name, '.');
	if (file_type)
	{
		if (!ft_strncnp(file_type, ".cub", 5))
			return (0);
	}
	ft_dprintf(STDERR_FILENO, "Error: not a .cub file");
	return (-1);
}

int	validate_open_file(char *file_name)
{
	int	fd;

	if (validate_file_type(file_name))
		return (-1);
	fd = open(file_name, O_RDONLY)
	if (fd > 2)
		return (fd);
	perror("Error when open file");
	return (-1);
}
