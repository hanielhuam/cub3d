/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_assets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:43:23 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/04/28 20:27:21 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



static int	attribute_assets(t_game *game, t_token *token)
{
	if (token->type == TK_NO)
		game->assets->no_texture = token->line;
	if (token->type == 
}

int	assign_assets(t_game *game, t_list *tokens)
{
	int	count;

	while (tokens && ((t_token *)tokens->content)->type != TK_MAP)
	{
		attribute_assets(game, (t_token *)tokens->content);
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
