#include "../include/cub3d.h"

int	close_window(t_game *game)
{
	del_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}