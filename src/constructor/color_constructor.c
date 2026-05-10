/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_constructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:17:42 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/09 22:08:36 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char **pre_process_color(char *line)
{	
	int		count;
	char	**split;
	char	*temp;

	split = ft_split(line, ',');
	if (!split)
	{
		ft_dprintf(STDERR_FILENO, "Error: unable to alloc split color\n");
		return (NULL);
	}
	count = 0;
	while (split[count])
	{
		temp = ft_strtrim(split[count], " ");
		if (!temp)
		{
			ft_dprintf(STDERR_FILENO, "Error: unable to trim color\n");
			del_split(split);
			return (NULL);
		}
		free(split[count]);
		split[count] = temp;
	}
	return (split);
}

static int	make_color_array(unsigned char *color, char *line)
{
	int		count;
	char	**split;
	int		result;

	split = pre_process_color(line);
	if (!split)
		return (1);
	count = 0;
	while (split[count])
	{
		result = ft_atoi(split[count]);
		if (result < 0 && result > 255)
		{
			ft_dprintf(STDERR_FILENO, "Error: color %d out of range\n", result);
			del_split(split);
			return (1);
		}
		color[count++] = (unsigned char)result;
	}
	del_split(split);
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
	line += 2;
	while (*line && ft_isspace(*line))
		line++;
	if (make_color_array(color, line))
	{
		free(color);
		return (NULL);
	}
	return (color);
}

int	floor_color_contructor(t_game *game, char *line)
{
	unsigned char	*color;

	color = extract_color(line);
	if (!color)
		return (1);
	game->assets->floor_color = color;
	return (0);
}

int	ceiling_color_contructor(t_game *game, char *line)
{
	unsigned char	*color

	color = extract_color(line);
	if (!color)
		return (1);
	game->assets->ceiling_color = color;
	return (0);
}
