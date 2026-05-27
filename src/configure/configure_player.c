/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:38:00 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/27 19:36:59 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_player(t_player *player)
{
	player->
}

static void	find_player(int *pos_x, int *pos_y, char **board)
{
	int	y;
	int	x;

	y = 0;
	while (board[y])
	{
		x = 0;
		while (board[y][x])
		{
			if (ft_strchr("NSWE", board[y][x]))
				break ;
			x++
		}
		y++;
	}
	pos_y = y + 0.5;
	pos_x = x + 0.5;
}

int	configure_player(t_game *game)
{
	t_player	player;

	player = ft_calloc(1, t_player);
	if (!player)
	{
		ft_dprintf(STDERR_FILENO, "Error: unable to alloc t_player\n");
		return (1);
	}
	find_player(&player->pos_x, &player->pos_y, game->board);
	calculate_player(t_player);
	return (0);
}
