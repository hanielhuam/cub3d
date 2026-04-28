/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 10:44:33 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/04/27 21:27:11 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_game	*calloc_game(void)
{
	t_game		*game;
	t_assats	*assets;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
	{
		ft_dprintf(STDERR_FILENO, "Error: unable to malloc t_game\n");
		return (NULL);
	}
	assets = ft_calloc(1, sizeof(t_assets));
	if (!assests)
	{
		ft_dprintf(STDERR_FILENO, "Error: unable to malloc t_assets\n");
		free(game);
		return (NULL);
	}
	game->assets = assets;
	return (game);
}

t_game	*create_game(t_list *tokens)
{
	t_game	*game;

	game = calloc_game();
	if (!game)
		return (NULL);
	
}
