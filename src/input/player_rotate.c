#include "../include/cub3d.h"

/* Rotates both direction and camera plane with a 2D rotation matrix. */
void	rotate_player(t_game *game)
{
	t_player	*player;
	double		angle;
	double		old_dir_x;
	double		old_plane_x;

	angle = (game->input.rotate_right - game->input.rotate_left) * ROT_SPEED;
	if (angle == 0)
		return ;
	player = game->player;
	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(angle) - player->dir_y * sin(angle);
	player->dir_y = old_dir_x * sin(angle) + player->dir_y * cos(angle);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(angle)
		- player->plane_y * sin(angle);
	player->plane_y = old_plane_x * sin(angle)
		+ player->plane_y * cos(angle);
}