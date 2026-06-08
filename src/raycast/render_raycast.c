#include "../include/cub3d.h"

/* Chooses a temporary solid color by wall side and ray direction. */
static int	wall_color(t_ray *ray)
{
	if (ray->side == 1 && ray->step_y < 0)
		return (0x4c8ed9);
	if (ray->side == 1 && ray->step_y > 0)
		return (0x2f5f9f);
	if (ray->side == 0 && ray->step_x < 0)
		return (0xd9824c);
	return (0x9f4f2f);
}

/* Converts wall distance into a vertical line clipped to the top screen. */
static void	get_wall_line(t_ray *ray, int *start, int *end)
{
	int	line_height;

	if (ray->perp_dist <= 0)
		ray->perp_dist = 0.0001;
	line_height = (int)(TOP_SCREEN_HEIGHT / ray->perp_dist);
	*start = -line_height / 2 + TOP_SCREEN_HEIGHT / 2;
	*end = line_height / 2 + TOP_SCREEN_HEIGHT / 2;
	if (*start < 1)
		*start = 1;
	if (*end >= TOP_SCREEN_HEIGHT - 1)
		*end = TOP_SCREEN_HEIGHT - 2;
}

/* Draws one vertical wall slice in the top development screen. */
static void	draw_wall_column(t_game *game, t_ray *ray, int x, int *line)
{
	int	y;
	int	color;

	color = wall_color(ray);
	y = line[0];
	while (y <= line[1])
		put_pixel(game->mlx->screen, x, y++, color);
}

/* Casts one ray per screen column and draws untextured wall slices. */
void	render_raycast(t_game *game)
{
	t_ray	ray;
	int		line[2];
	int		x;

	x = 1;
	while (x < WIDITH - 1)
	{
		init_ray(&ray, game->player, x);
		run_dda(&ray, game->board);
		get_wall_line(&ray, &line[0], &line[1]);
		draw_wall_column(game, &ray, x, line);
		x++;
	}
}