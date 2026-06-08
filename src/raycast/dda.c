#include "../include/cub3d.h"

/* Treats walls, spaces, missing rows and short rows as blocking cells. */
static int	is_wall(char **board, int x, int y)
{
	if (y < 0 || x < 0 || !board[y])
		return (1);
	if (x >= (int)ft_strlen(board[y]))
		return (1);
	if (board[y][x] == '1' || board[y][x] == ' ')
		return (1);
	return (0);
}

/* Advances through the map grid until the ray reaches a blocking cell. */
void	run_dda(t_ray *ray, char **board)
{
	while (!is_wall(board, ray->map_x, ray->map_y))
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
	}
	if (ray->side == 0)
		ray->perp_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_dist = ray->side_dist_y - ray->delta_dist_y;
}