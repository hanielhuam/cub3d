#include "cub3d.h"

/* Returns the 3D viewport height for production or debug mode. */
int	view_height(t_game *game)
{
	if (game->debug_view)
		return (TOP_SCREEN_HEIGHT);
	return (HEIGHT);
}

/* Paints ceiling and floor colors inside the active 3D viewport. */
void	render_background(t_game *game)
{
	int	ceiling;
	int	floor;
	int	height;
	int	pos[2];
	int	size[2];

	height = view_height(game);
	ceiling = rgb_to_int(game->assets->ceiling_color);
	floor = rgb_to_int(game->assets->floor_color);
	pos[0] = 0;
	pos[1] = 0;
	size[0] = WIDTH;
	size[1] = height / 2;
	draw_rect(game->mlx->screen, pos, size, ceiling);
	pos[1] = height / 2;
	size[1] = height - pos[1];
	draw_rect(game->mlx->screen, pos, size, floor);
}