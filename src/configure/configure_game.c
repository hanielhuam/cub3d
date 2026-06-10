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

#include "../include/cub3d.h"

/* Allocates the MLX and screen wrappers before creating native resources. */
static int	alloc_mlx_data(t_game *game)
{
	t_mlx	*mlx;
	t_img	*screen;

	mlx = ft_calloc(1, sizeof(t_mlx));
	screen = ft_calloc(1, sizeof(t_img));
	if (!mlx || !screen)
	{
		ft_dprintf(STDERR_FILENO, "Error: unable to alloc t_mlx or t_img\n");
		free(mlx);
		free(screen);
		return (1);
	}
	mlx->screen = screen;
	game->mlx = mlx;
	return (0);
}

/* Creates the MLX context and its window with checked return values. */
static int	create_mlx_window(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
	{
		ft_dprintf(STDERR_FILENO, "Error: mlx_init failed\n");
		return (1);
	}
	mlx->window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Cub3d");
	if (!mlx->window)
	{
		ft_dprintf(STDERR_FILENO, "Error: window creation failed\n");
		return (1);
	}
	return (0);
}

/* Creates the frame image and obtains its writable pixel buffer. */
static int	create_screen_image(t_mlx *mlx)
{
	t_img	*screen;

	screen = mlx->screen;
	screen->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!screen->img)
	{
		ft_dprintf(STDERR_FILENO, "Error: image creation failed\n");
		return (1);
	}
	screen->addr = mlx_get_data_addr(screen->img, &screen->bpp,
			&screen->line_length, &screen->endian);
	if (!screen->addr)
	{
		ft_dprintf(STDERR_FILENO, "Error: image address failed\n");
		return (1);
	}
	return (0);
}

/* Initializes all MLX resources in dependency order. */
static int	config_mlx(t_game *game)
{
	if (alloc_mlx_data(game))
		return (1);
	if (create_mlx_window(game->mlx))
		return (1);
	if (create_screen_image(game->mlx))
		return (1);
	return (0);
}

/* Prepares graphics first and the player state after it succeeds. */
int	configure_game(t_game *game)
{
	if (config_mlx(game) || config_player(game))
		return (1);
	return (0);
}
