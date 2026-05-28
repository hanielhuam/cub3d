/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:38:00 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/28 19:46:27 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	find_player(double *pos_x, double *pos_y, char **board)
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
			{
				*pos_y = y + 0.5;
				*pos_x = x + 0.5;
				return (board[y][x]);
			}
			x++;
		}
		y++;
	}
	*pos_y = y + 0.5;
	*pos_x = x + 0.5;
	return (board[y][x]);
}

static void init_plane(t_player *player, double plane_y, double plane_x)
{
	player->plane_y = plane_y;
	player->plane_x = plane_x;
}

static void init_dir(t_player *player, double dir_y, double dir_x, char chr)
{
	player->dir_y = dir_y;
	player->dir_x = dir_x;
	if (chr == 'N')
		init_plane(player, 0.0, 0.66);
	else if (chr == 'S')
		init_plane(player, 0.0, -0.66);
	else if (chr == 'W')
		init_plane(player, -0.66, 0);
	else if (chr == 'E')
		init_plane(player, 0.66, 0.0);
}

static void	init_player(t_player *player, char chr)
{
	if (chr == 'N')
		init_dir(player, -1.0, 0.0, chr);
	else if (chr == 'S')
		init_dir(player, 1.0, 0.0, chr);
	else if (chr == 'W')
		init_dir(player, 0.0, -1.0, chr);
	else if (chr == 'E')
		init_dir(player, 0.0, 1.0, chr);
}

int	config_player(t_game *game)
{
	char		chr;
	t_player	*player;

	player = ft_calloc(1, sizeof(t_player));
	if (!player)
	{
		ft_dprintf(STDERR_FILENO, "Error: unable to alloc t_player\n");
		return (1);
	}
	chr = find_player(&player->pos_x, &player->pos_y, game->board);
	init_player(player, chr);
	game->player = player;
	return (0);
}
