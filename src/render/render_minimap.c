#include "../include/cub3d.h"

/* Returns the widest map row so the minimap can be centered. */
static int	map_width(char **board)
{
	int	width;
	int	y;

	width = 0;
	y = 0;
	while (board[y])
	{
		if ((int)ft_strlen(board[y]) > width)
			width = ft_strlen(board[y]);
		y++;
	}
	return (width);
}

/* Returns the number of map rows so the minimap can be centered vertically. */
static int	map_height(char **board)
{
	int	height;

	height = 0;
	while (board[height])
		height++;
	return (height);
}

/* Chooses a simple color for each kind of map tile. */
static int	tile_color(char tile)
{
	if (tile == '1')
		return (0x303030);
	if (tile == '0')
		return (0xc8d8c0);
	if (ft_strchr("NSWE", tile))
		return (0xff4040);
	return (0x101010);
}

/* Draws all map tiles starting from the centered bottom-screen offset. */
static void	draw_map_tiles(t_game *game, int offset_x, int offset_y)
{
	int	pos[2];
	int	size[2];
	int	x;
	int	y;

	size[0] = MINIMAP_SCALE - 1;
	size[1] = MINIMAP_SCALE - 1;
	y = 0;
	while (game->board[y])
	{
		x = 0;
		while (game->board[y][x])
		{
			pos[0] = offset_x + x * MINIMAP_SCALE;
			pos[1] = offset_y + y * MINIMAP_SCALE;
			draw_rect(game->mlx->screen, pos, size,
				tile_color(game->board[y][x]));
			x++;
		}
		y++;
	}
}

/* Centers and renders the minimap inside the lower development screen. */
void	render_minimap(t_game *game)
{
	int	offset_x;
	int	offset_y;
	int	width;
	int	height;
	int	bottom_height;

	width = map_width(game->board) * MINIMAP_SCALE;
	height = map_height(game->board) * MINIMAP_SCALE;
	bottom_height = HEIGHT - TOP_SCREEN_HEIGHT;
	offset_x = (WIDITH - width) / 2;
	offset_y = TOP_SCREEN_HEIGHT + (bottom_height - height) / 2;
	draw_map_tiles(game, offset_x, offset_y);
}