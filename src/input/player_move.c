#include "../include/cub3d.h"

/* Returns whether a world position belongs to a floor cell. */
static int	can_move(char **board, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_y < 0 || !board[map_y])
		return (0);
	if (map_x >= (int)ft_strlen(board[map_y]))
		return (0);
	return (board[map_y][map_x] == '0');
}

/* Applies movement independently on each axis with a collision margin. */
static void	move_player(t_game *game, double move_x, double move_y)
{
	t_player	*player;

	player = game->player;
	if (can_move(game->board, player->pos_x + move_x, player->pos_y - 0.15)
		&& can_move(game->board, player->pos_x + move_x,
			player->pos_y + 0.15))
		player->pos_x += move_x;
	if (can_move(game->board, player->pos_x - 0.15,
			player->pos_y + move_y)
		&& can_move(game->board, player->pos_x + 0.15,
			player->pos_y + move_y))
		player->pos_y += move_y;
}

/* Prevents diagonal input from increasing movement speed. */
static double	movement_scale(int front, int side)
{
	if (front && side)
		return (0.707106);
	return (1.0);
}

/* Converts current key states into a movement vector. */
static void	update_translation(t_game *game)
{
	t_player	*player;
	double		move_x;
	double		move_y;
	int			front;
	int			side;

	player = game->player;
	front = game->input.forward - game->input.backward;
	side = game->input.right - game->input.left;
	move_x = (player->dir_x * front - player->dir_y * side) * MOVE_SPEED
		* movement_scale(front, side);
	move_y = (player->dir_y * front + player->dir_x * side) * MOVE_SPEED
		* movement_scale(front, side);
	move_player(game, move_x, move_y);
}

/* Updates translation and camera rotation once per frame. */
void	update_player(t_game *game)
{
	update_translation(game);
	rotate_player(game);
}