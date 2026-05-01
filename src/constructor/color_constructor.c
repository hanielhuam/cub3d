/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_constructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:17:42 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/01 18:47:10 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned char	extract_one_color(char **line)
{
	
}

static unsigned char	*extract_colors(char *line)
{
	unsigned char	*color;

	if (color_validation(line))
		return (NULL);
	color = (unsigned char *)ft_calloc(3, sizeof(char));
	if (!color)
	{
		ft_dprintf(STDERR_FILENO, "Error: can´t malloc color\n");
		return (NULL);
	}
	line =+ 2;
	while (*line && ft_isspace(*line))
		line++;
	count = 0;
	while (count < 3)
		color[count++] = extract_one_color(&line);
	return (color);
}

int	floor_color_contructor(t_game *game, char *line)
{
	unsigned char	*color

	color = extract_color(line);
	if (!color)
		return (1);
	game->assets->floor_color = color;
	return (0);
}

int	ceiling_color_contructor(t_game *game, char *line)
{
	(void)game;
	(void)line;
	return (0);
}
