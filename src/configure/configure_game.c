/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 19:10:52 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/26 21:22:35 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*config_mlx(t_game *game)
{
	t_mlx	*mlx;
	t_img	*screen;

	mlx = ft_calloc(1, sizeof(t_mlx));
	screen = ft_calloc(1, sizeof(t_img));
	if (!mlx || !screen)
	{
		ft_dprintf(STDERR_FILENO, "Error: unable to alloc t_mlx or t_img\n");
		return (1);
	}
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIDITH, HEIGHT, "Cub3d");
	screen->img = mlx_new_image(mlx->mlx, WIDITH, HEIGHT);
	screen->addr = mlx_get_data_addr(screen->img, &screen->bpp,
		&screen->line_lenght, &screen->endian);
	mlx->screen = screen;
	game->mlx = mlx;
	return (0);
}

int	configure_game(t_game *game)
{
	if (config_mlx(game) || config_player(game))
		return (1);
	return (0);
}
