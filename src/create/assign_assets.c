/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_assets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:43:23 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/04/29 21:27:18 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	attribute_assets(t_game *game, t_token *token)
{
	t_tok_type	type;
	static int	(*assets_constructors[6])(t_game *, char *line) = {
		no_texture_constructor,
		so_texture_constructor,
		ea_texture_constructor,
		we_texture_constructor,
		floor_color_constructor,
		ceiling_color_constructor
	};

	if (token->type == TK_NL)
		return (0);
	type = token->type;
	return (assets_constructors[type](game, token->line));
}

int	assign_assets(t_game *game, t_list *tokens)
{
	int	count;

	while (tokens && ((t_token *)tokens->content)->type != TK_MAP)
	{
		if (attribute_assets(game, (t_token *)tokens->content))
		tokens = tokens->next;
	}
	count = 0;
	while (tokens && ((t_token *)tokens->content)->type == TK_MAP)
	{
		count++;
		tokens = tokens->next;
	}
	return (count);
}
