#include "../include/cub3d.h"

/* Loads one XPM image and exposes its pixel buffer. */
static int	load_texture(t_game *game, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(game->mlx->mlx, path,
			&texture->width, &texture->height);
	if (!texture->img)
	{
		ft_dprintf(STDERR_FILENO, "Error\nunable to load texture %s\n", path);
		return (1);
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_length, &texture->endian);
	if (!texture->addr)
	{
		ft_dprintf(STDERR_FILENO, "Error\nunable to read texture %s\n", path);
		return (1);
	}
	return (0);
}

/* Loads all directional wall textures in parser order. */
int	config_textures(t_game *game)
{
	t_assets	*assets;

	assets = game->assets;
	if (load_texture(game, &assets->no, assets->no_texture))
		return (1);
	if (load_texture(game, &assets->so, assets->so_texture))
		return (1);
	if (load_texture(game, &assets->we, assets->we_texture))
		return (1);
	if (load_texture(game, &assets->ea, assets->ea_texture))
		return (1);
	return (0);
}