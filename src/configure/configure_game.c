/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 19:10:52 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/26 18:19:02 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_config(t_mlx *mlx)
{
	t_img	*screen;

	screen = ft_calloc(1, sizeof(t_img));
	if (!screen)
	{
		ft_dprintf(STDERR_FILENO, "Error: unable to alloc screen\n");
		return (1);
	}
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIDITH, HEIGHT, "Cub3d");
	screen->img = mlx_new_image(mlx->mlx, WIDITH, HEIGHT);
	screen->addr = mlx_get_data_addr(screen->img, &screen->bpp,
		&screen->line_lenght, &screen->endian);
	mlx->screen = screen;
	return (0);
}

int	configure_game(t_game *game)
{
	t_mlx	*mlx;

	mlx = ft_calloc(1, sizeof(t_mlx));
	if (!mlx)
	{
		ft_dprintf(STDERR_FILENO, "Error: unable to alloc t_mlx\n");
		return (1);
	}
	if (init_config(mlx))
	{
		free(mlx);
		return (1);
	}
	game->mlx = mlx;
	return (0);
}
