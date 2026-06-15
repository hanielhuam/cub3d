#include "cub3d.h"

/* Runs parser and map validation without initializing MiniLibX. */
int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc_validation(argc))
		return (1);
	game = create_validate_game(argv[1]);
	if (!game)
		return (1);
	del_game(game);
	return (0);
}