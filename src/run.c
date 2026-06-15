/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 19:55:33 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/26 20:15:16 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(t_game *game)
{
	update_player(game);
	return (render_frame(game));
}

void	run(t_game *game)
{
	setup_hooks(game);
	mlx_loop_hook(game->mlx->mlx, game_loop, game);
	mlx_loop(game->mlx->mlx);
}
