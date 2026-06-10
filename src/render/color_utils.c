#include "../include/cub3d.h"

/* Converts three RGB bytes to the integer color format used by MiniLibX. */
int	rgb_to_int(unsigned char *rgb)
{
	if (!rgb)
		return (0);
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}