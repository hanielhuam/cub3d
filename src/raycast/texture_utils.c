#include "cub3d.h"

/* Selects the texture matching the wall face hit by the ray. */
t_texture	*get_wall_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0 && ray->step_x > 0)
		return (&game->assets->we);
	if (ray->side == 0)
		return (&game->assets->ea);
	if (ray->step_y > 0)
		return (&game->assets->no);
	return (&game->assets->so);
}

/* Reads one pixel from a loaded texture with bounds checking. */
int	texture_pixel(t_texture *texture, int x, int y)
{
	char	*pixel;

	if (x < 0 || y < 0 || x >= texture->width || y >= texture->height)
		return (0);
	pixel = texture->addr + y * texture->line_length
		+ x * (texture->bpp / 8);
	return (*(unsigned int *)pixel);
}