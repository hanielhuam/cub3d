

#include "cub3d.h"

t_game  *create_validate_game(char *file_game)
{
    int     fd;
    t_game  *game;

    fd = validate_open_file(file_game);
    if (fd < 0)
        return (NULL);
    game = validate_game_file(fd);
    if (!game)
        return (NULL);
    if (!validate_game(game))
        return (game);
    del_game(game);
    return (NULL);
}