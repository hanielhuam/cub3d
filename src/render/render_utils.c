#include "../include/cub3d.h"

/* Writes one pixel in the MLX image only when it is inside the window. */
void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIDITH || y >= HEIGHT)
		return ;
	dst = img->addr + (y * img->line_lenght + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

/* Fills the whole screen image with one background color. */
void	clear_screen(t_img *img, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDITH)
			put_pixel(img, x++, y, color);
		y++;
	}
}

/* Draws a filled rectangle using pos[0..1] and size[0..1]. */
void	draw_rect(t_img *img, int *pos, int *size, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < size[1])
	{
		x = 0;
		while (x < size[0])
			put_pixel(img, pos[0] + x++, pos[1] + y, color);
		y++;
	}
}

/* Draws only the border of a rectangle using pos[0..1] and size[0..1]. */
void	draw_wireframe(t_img *img, int *pos, int *size, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < size[0])
	{
		put_pixel(img, pos[0] + x, pos[1], color);
		put_pixel(img, pos[0] + x++, pos[1] + size[1] - 1, color);
	}
	y = 0;
	while (y < size[1])
	{
		put_pixel(img, pos[0], pos[1] + y, color);
		put_pixel(img, pos[0] + size[0] - 1, pos[1] + y++, color);
	}
}