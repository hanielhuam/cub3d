#include "../include/cub3d.h"

/* Draws the two development screens: top 3D area and bottom minimap area. */
static void	render_wireframes(t_game *game)
{
	int	pos[2];
	int	size[2];

	pos[0] = 0;
	pos[1] = 0;
	size[0] = WIDITH;
	size[1] = TOP_SCREEN_HEIGHT;
	draw_wireframe(game->mlx->screen, pos, size, 0xe8e8e8);
	pos[1] = TOP_SCREEN_HEIGHT;
	size[1] = HEIGHT - TOP_SCREEN_HEIGHT;
	draw_wireframe(game->mlx->screen, pos, size, 0xe8e8e8);
}

/* Renders one debug frame and sends it to the MLX window. */
int	render_frame(t_game *game)
{
	clear_screen(game->mlx->screen, 0x101010);
	render_wireframes(game);
	render_minimap(game);
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->window,
		game->mlx->screen->img, 0, 0);
	return (0);
}