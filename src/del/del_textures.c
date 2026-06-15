#include "cub3d.h"

/* Destroys one loaded texture when an MLX context exists. */
static void	del_texture(void *mlx, t_texture *texture)
{
	if (mlx && texture->img)
		mlx_destroy_image(mlx, texture->img);
	texture->img = NULL;
	texture->addr = NULL;
}

/* Destroys every directional texture before the MLX display. */
void	del_textures(t_game *game)
{
	void	*mlx;

	if (!game->assets || !game->mlx)
		return ;
	mlx = game->mlx->mlx;
	del_texture(mlx, &game->assets->no);
	del_texture(mlx, &game->assets->so);
	del_texture(mlx, &game->assets->we);
	del_texture(mlx, &game->assets->ea);
}