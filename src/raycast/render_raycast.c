#include "cub3d.h"

/* Projects perpendicular distance into a clipped wall column. */
static void	get_wall_line(t_game *game, t_ray *ray, t_wall *wall)
{
	int	height;

	height = view_height(game);
	if (ray->perp_dist <= 0)
		ray->perp_dist = 0.0001;
	wall->height = (int)(height / ray->perp_dist);
	if (wall->height < 1)
		wall->height = 1;
	wall->draw_start = -wall->height / 2 + height / 2;
	wall->draw_end = wall->height / 2 + height / 2;
	if (wall->draw_start < 0)
		wall->draw_start = 0;
	if (wall->draw_end >= height)
		wall->draw_end = height - 1;
}

/* Calculates the horizontal texture coordinate and vertical sampling step. */
static void	init_texture(t_game *game, t_ray *ray, t_wall *wall,
	t_texture *texture)
{
	int	height;

	height = view_height(game);
	if (ray->side == 0)
		wall->wall_x = game->player->pos_y + ray->perp_dist * ray->dir_y;
	else
		wall->wall_x = game->player->pos_x + ray->perp_dist * ray->dir_x;
	wall->wall_x -= floor(wall->wall_x);
	wall->tex_x = (int)(wall->wall_x * texture->width);
	if ((ray->side == 0 && ray->dir_x > 0)
		|| (ray->side == 1 && ray->dir_y < 0))
		wall->tex_x = texture->width - wall->tex_x - 1;
	wall->tex_step = (double)texture->height / wall->height;
	wall->tex_pos = (wall->draw_start - height / 2 + wall->height / 2)
		* wall->tex_step;
}

/* Samples and draws one textured wall column. */
static void	draw_wall_column(t_game *game, t_wall *wall,
	t_texture *texture, int x)
{
	int	color;
	int	tex_y;
	int	y;

	y = wall->draw_start;
	while (y <= wall->draw_end)
	{
		tex_y = (int)wall->tex_pos;
		wall->tex_pos += wall->tex_step;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= texture->height)
			tex_y = texture->height - 1;
		color = texture_pixel(texture, wall->tex_x, tex_y);
		put_pixel(game->mlx->screen, x, y++, color);
	}
}

/* Casts and draws one textured ray for every viewport column. */
void	render_raycast(t_game *game)
{
	t_texture	*texture;
	t_ray	ray;
	t_wall	wall;
	int		x;

	x = 1;
	while (x < WIDTH - 1)
	{
		init_ray(&ray, game->player, x);
		run_dda(&ray, game->board);
		texture = get_wall_texture(game, &ray);
		get_wall_line(game, &ray, &wall);
		init_texture(game, &ray, &wall, texture);
		draw_wall_column(game, &wall, texture, x);
		x++;
	}
}