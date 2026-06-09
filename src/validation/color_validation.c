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

#include "cub3d.h"

static void	skip_spaces(char *line, int *index)
{
	while (line[*index] && ft_isspace(line[*index]))
		(*index)++;
}

static int	read_component(char *line, int *index)
{
	int	digits;

	digits = 0;
	skip_spaces(line, index);
	while (ft_isdigit(line[*index]))
	{
		digits++;
		(*index)++;
	}
	skip_spaces(line, index);
	return (digits > 0);
}

static int	valid_color_format(char *line)
{
	int	component;
	int	index;

	component = 0;
	index = 0;
	skip_spaces(line, &index);
	if (line[index] != 'F' && line[index] != 'C')
		return (0);
	index++;
	while (component < 3)
	{
		if (!read_component(line, &index))
			return (0);
		component++;
		if (component < 3 && line[index++] != ',')
			return (0);
	}
	return (line[index] == '\0');
}

int	color_validation(char *line)
{
	if (!valid_color_format(line))
	{
		ft_dprintf(STDERR_FILENO,
			"Error: color isn't formatted properly\n");
		return (1);
	}
	return (0);
}
