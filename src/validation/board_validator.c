/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 20:41:50 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/16 14:20:56 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_player(char **board)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	y = 0;
	while (board[y])
	{
		x = 0;
		while (board[y][x])
		{
			if (ft_strchr("NSEW", board[y][x]))
				count++;
			x++;
		}
		y++;
	}
	if (count == 1)
		return (0);
	ft_dprintf(STDERR_FILENO,
		"Error: player appears %d times on the board\n", count);
	return (1);
}

static char	map_at(char **board, int x, int y)
{
	if (y < 0 || x < 0 || !board[y])
		return (' ');
	if (x >= (int)ft_strlen(board[y]))
		return (' ');
	return (board[y][x]);
}

static int	has_open_neighbor(char **board, int x, int y)
{
	if (map_at(board, x + 1, y) == ' '
		|| map_at(board, x - 1, y) == ' '
		|| map_at(board, x, y + 1) == ' '
		|| map_at(board, x, y - 1) == ' ')
		return (1);
	return (0);
}

static int	check_closed(char **board)
{
	int	x;
	int	y;

	y = 0;
	while (board[y])
	{
		x = 0;
		while (board[y][x])
		{
			if (ft_strchr("0NSEW", board[y][x])
				&& has_open_neighbor(board, x, y))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	board_validator(char **board)
{
	if (check_player(board))
		return (1);
	if (check_closed(board))
	{
		ft_dprintf(STDERR_FILENO,
			"Error: the map isn't totally closed\n");
		return (1);
	}
	return (0);
}
