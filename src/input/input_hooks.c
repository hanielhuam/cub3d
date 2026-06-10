#include "../include/cub3d.h"

/* Handles immediate keyboard commands registered by MiniLibX. */
int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	return (0);
}

/* Registers window and keyboard events in one input module. */
void	setup_hooks(t_game *game)
{
	mlx_hook(game->mlx->window, 17, 0, close_window, game);
	mlx_hook(game->mlx->window, 2, 1L << 0, handle_key_press, game);
}