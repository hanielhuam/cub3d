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
static void	get_wall_line(t_ray *ray, t_wall *wall)
{
	if (ray->perp_dist <= 0)
		ray->perp_dist = 0.0001;
	wall->height = (int)(TOP_SCREEN_HEIGHT / ray->perp_dist);
	wall->draw_start = -wall->height / 2 + TOP_SCREEN_HEIGHT / 2;
	wall->draw_end = wall->height / 2 + TOP_SCREEN_HEIGHT / 2;
	if (wall->draw_start < 1)
		wall->draw_start = 1;
	if (wall->draw_end >= TOP_SCREEN_HEIGHT - 1)
		wall->draw_end = TOP_SCREEN_HEIGHT - 2;
}

/* Draws one vertical wall slice in the top development screen. */
static void	draw_wall_column(t_game *game, t_wall *wall, int x)
{
	int	limits[2];

	limits[0] = wall->draw_start;
	limits[1] = wall->draw_end;
	draw_vertical_line(game->mlx->screen, x, limits, wall->color);
}

/* Casts one ray per screen column and draws untextured wall slices. */
void	render_raycast(t_game *game)
{
	t_ray	ray;
	t_wall	wall;
	int		x;

	x = 1;
	while (x < WIDTH - 1)
	{
		init_ray(&ray, game->player, x);
		run_dda(&ray, game->board);
		wall.color = wall_color(&ray);
		get_wall_line(&ray, &wall);
		draw_wall_column(game, &wall, x);
		x++;
	}
}