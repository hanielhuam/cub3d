/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 22:40:01 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/13 19:59:25 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	color_validation(char *line)
{
	int	count;

	count = 2;
	while (line[count])
	{
		if (!(ft_isdigit(line[count]) || line[count] == ','))
		{
			ft_dprintf(STDERR_FILENO, "Error: color isn't formated properly\n");
			return (1);
		}
		count++;
	}
	return (0);
}
