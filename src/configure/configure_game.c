/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 19:10:52 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/21 19:51:01 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_config(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, 1280, 720, "Cub3d");
	mlx->img = mlx_new_image(mlx->mlx, 1280, 720);
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
	init_config(mlx);
	game->mlx = mlx;
	return (0);
}
