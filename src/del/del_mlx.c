/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 18:23:03 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/25 20:01:37 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	del_mlx(t_mlx *mlx)
{
	if (!mlx)
		return ;
	if (mlx->mlx && mlx->screen && mlx->screen->img)
		mlx_destroy_image(mlx->mlx, mlx->screen->img);
	if (mlx->mlx && mlx->window)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
	free(mlx->screen);
	free(mlx);
}
