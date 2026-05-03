/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 10:44:33 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/03 00:30:03 by hmacedo-         ###   ########.fr       */
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
	int		board_lenght;
	char	**bord;

	game = calloc_game();
	if (!game)
		return (NULL);
	board_lenght = assign_assets(game, tokens);
	if (!board_lenght)
	{
		del_game(game);
		return (NULL);
	}
	board = map_constructor(tokens, board_lenght);
	if (!board)
	{
		del_game(game);
		return (NULL);
	}
}
