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

void	run(t_game *game)
{
	mlx_hook(game->mlx->window, 17, 0, close_window, game);
	mlx_loop_hook(game->mlx->mlx, render_frame, game);
	mlx_loop(game->mlx->mlx);
}
