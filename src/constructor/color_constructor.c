/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_constructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:17:42 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/13 19:43:56 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	floor_color_constructor(t_game *game, char *line)
{
	unsigned char	*color;

	color = extract_colors(line);
	if (!color)
		return (1);
	game->assets->floor_color = color;
	return (0);
}

int	ceiling_color_constructor(t_game *game, char *line)
{
	unsigned char	*color;

	color = extract_colors(line);
	if (!color)
		return (1);
	game->assets->ceiling_color = color;
	return (0);
}
