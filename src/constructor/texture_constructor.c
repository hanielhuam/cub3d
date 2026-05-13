/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_constructor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:17:29 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/13 16:05:31 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*extract_texture(char *line, char *errmsg)
{
	line = line + 3;
	while (*line && ft_isspace(*line))
		line++;
	if (!*line)
	{
		ft_dprintf(STDERR_FILENO, errmsg);	
		return (NULL);
	}
	return (dup_str(line));
}

int	no_texture_constructor(t_game *game, char *line)
{
	char	*texture;

	texture = extract_texture(line, \
			"Error: there is no value for NO texture\n");
	if (!texture)
		return (1);
	game->assets->no_texture = texture;
	return (0);
}

int	so_texture_constructor(t_game *game, char *line)
{
	char	*texture;

	texture = extract_texture(line, \
			"Error: there is no value for SO texture\n");
	if (!texture)
		return (1);
	game->assets->so_texture = texture;
	return (0);
}
int	ea_texture_constructor(t_game *game, char *line)
{
	char	*texture;

	texture = extract_texture(line, \
			"Error: there is no value for EA texture\n");
	if (!texture)
		return (1);
	game->assets->ea_texture = texture;
	return (0);
}
int	we_texture_constructor(t_game *game, char *line)
{
	char	*texture;

	texture = extract_texture(line, \
			"Error: there is no value for WE texture\n");
	if (!texture)
		return (1);
	game->assets->we_texture = texture;
	return (0);
}
