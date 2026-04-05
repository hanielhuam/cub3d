/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_validate_game.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 20:30:21 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/04/05 20:32:22 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	*create_validate_game(char *file_game)
{
    int		fd;
    t_game	*game;

	fd = validate_open_file(file_game);
	if (fd < 0)
		return (NULL);
	game = validate_game_file(fd);
	close(fd);
	if (!game)
		return (NULL);
	if (!validate_game(game))
		return (game);
	del_game(game);
	return (NULL);
}
