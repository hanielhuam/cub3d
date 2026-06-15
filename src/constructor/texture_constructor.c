/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_constructor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:17:29 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/15 14:01:15 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static char	*extract_texture(char *line, char *errmsg)
{
	char	*texture;

	while (*line && ft_isspace(*line))
		line++;
	line += 2;
	while (*line && ft_isspace(*line))
		line++;
	if (!*line)
	{
		ft_dprintf(STDERR_FILENO, "%s", errmsg);
		return (NULL);
	}
	texture = ft_strtrim(line, " \t\v\f\r");
	if (!texture)
		ft_dprintf(STDERR_FILENO, "Error\nunable to allocate texture path\n");
	return (texture);
}

int	no_texture_constructor(t_game *game, char *line)
{
	char	*texture;

	texture = extract_texture(line,
			"Error\nthere is no value for NO texture\n");
	if (!texture)
		return (1);
	game->assets->no_texture = texture;
	return (0);
}

int	so_texture_constructor(t_game *game, char *line)
{
	char	*texture;

	texture = extract_texture(line,
			"Error\nthere is no value for SO texture\n");
	if (!texture)
		return (1);
	game->assets->so_texture = texture;
	return (0);
}

int	ea_texture_constructor(t_game *game, char *line)
{
	char	*texture;

	texture = extract_texture(line,
			"Error\nthere is no value for EA texture\n");
	if (!texture)
		return (1);
	game->assets->ea_texture = texture;
	return (0);
}

int	we_texture_constructor(t_game *game, char *line)
{
	char	*texture;

	texture = extract_texture(line,
			"Error\nthere is no value for WE texture\n");
	if (!texture)
		return (1);
	game->assets->we_texture = texture;
	return (0);
}
