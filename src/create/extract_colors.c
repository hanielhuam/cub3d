/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:41:26 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/14 16:17:50 by hmacedo-         ###   ########.fr       */
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
		split[count++] = temp;
	}
	return (split);
}

static int	is_3_colors(char **split)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	if (count == 3)
		return (1);
	ft_dprintf(STDERR_FILENO, "Error: color is composed by 3 elements\n");
	return (0);
}

static int	make_color_array(unsigned char *color, char *line)
{
	int		count;
	char	**split;
	int		result;

	split = pre_process_color(line);
	if (!split || !is_3_colors(split))
		return (1);
	count = 0;
	while (split[count])
	{
		result = ft_atoi(split[count]);
		if (result < 0 || result > 255)
		{
			ft_dprintf(STDERR_FILENO, "Error: color %d out of range\n", result);
			del_split(split);
			return (1);
		}
		color[count++] = (unsigned char)result;
	}
	del_split(split);
	return (0);
}

unsigned char	*extract_colors(char *line)
{
	unsigned char	*colors;

	if (color_validation(line))
		return (NULL);
	colors = (unsigned char *)ft_calloc(3, sizeof(char));
	if (!colors)
	{
		ft_dprintf(STDERR_FILENO, "Error: can´t malloc color\n");
		return (NULL);
	}
	line += 2;
	while (*line && ft_isspace(*line))
		line++;
	if (make_color_array(colors, line))
	{
		free(colors);
		return (NULL);
	}
	return (colors);
}
