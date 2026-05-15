/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 20:39:46 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/14 22:06:21 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_assets_file(t_assets *assets)
{
	if (check_file(assets->no_texture)\
			|| check_file(assets->so_texture)\
			|| check_file(assets->we_texture)\
			|| check_file(assets->ea_texture))
		return (1);
	return (0);
}

int	validate_game(t_game *game)
{
	if (check_assets_file(game->assets))
		return (1);
	if (board_validator(game->board))
		return (1);
	return (0);
}
