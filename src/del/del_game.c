

#include "cub3d.h"

void    del_assts(t_assetes *assets)
{
    free(assets->no_texture);
    free(assets->so_texture);
    free(assets->we_texture);
    free(assets->ea_texture);
    free(assets->floor_color);
    free(assets->ceiling_color);
}

void    del_board(char **board)
{
    char *temp;

    temp = *board;
    while (temp)
        free(temp++);
    free(board);
}

void    del_game(t_game *game)
{
    if (!game || !*game)
        return ;
    if (game->assets)
        del_assts(game->assets);
    if (game->board)
        del_board(game->board);
}