#include "../include/cub3d.h"

/* Updates one movement or rotation key state. */
static void	set_key(t_input *input, int keycode, int value)
{
	if (keycode == KEY_W)
		input->forward = value;
	else if (keycode == KEY_S)
		input->backward = value;
	else if (keycode == KEY_A)
		input->left = value;
	else if (keycode == KEY_D)
		input->right = value;
	else if (keycode == KEY_LEFT)
		input->rotate_left = value;
	else if (keycode == KEY_RIGHT)
		input->rotate_right = value;
}

/* Handles commands and marks held keys as pressed. */
int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	else if (keycode == KEY_M)
		game->debug_view = !game->debug_view;
	else
		set_key(&game->input, keycode, 1);
	return (0);
}

/* Clears a held key when X11 reports its release. */
int	handle_key_release(int keycode, t_game *game)
{
	set_key(&game->input, keycode, 0);
	return (0);
}

/* Registers window and keyboard events in one input module. */
void	setup_hooks(t_game *game)
{
	mlx_hook(game->mlx->window, 17, 0, close_window, game);
	mlx_hook(game->mlx->window, 2, 1L << 0, handle_key_press, game);
	mlx_hook(game->mlx->window, 3, 1L << 1, handle_key_release, game);
}