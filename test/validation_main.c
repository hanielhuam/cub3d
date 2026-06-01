#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_dprintf(STDERR_FILENO, "Usage: %s <map.cub>\n", argv[0]);
		return (2);
	}
	game = create_validate_game(argv[1]);
	if (!game)
		return (1);
	del_game(game);
	return (0);
}