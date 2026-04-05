

#include "cub3d.h"

void    del_assets(t_assets *assets)
{
    if (assets->no_texture)
        free(assets->no_texture);
    if (assets->so_texture)
        free(assets->so_texture);
    if (assets->we_texture)
        free(assets->we_texture);
    if (assets->ea_texture)
        free(assets->ea_texture);
    if (assets->floor_color)
        free(assets->floor_color);
    if (assets->ceiling_color)
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
    if (!game)
        return ;
    if (game->assets)
        del_assts(game->assets);
    if (game->board)
        del_board(game->board);
}