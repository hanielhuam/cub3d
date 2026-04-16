/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 10:44:33 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/04/16 18:41:43 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_game	*calloc_game(void)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
	{
		ft_dprintf(STDERR_FILENO, "Error: unable to malloc t_game\n");
		return (NULL);
	}
	return (game);
}

t_game	*create_game(t_token *tokens)
{
	t_game	*game;

	game = calloc_game(1, sizeof(t_game));
	if (!game)
		return (NULL);
}
