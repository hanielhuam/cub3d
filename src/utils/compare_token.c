/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 19:36:14 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/04/11 21:52:47 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_token	*get_rsources_tokens(void)
{
	t_token	tokens[6] = {
	{TK_NO, "NO"},
	{TK_SO, "SO"},
	{TK_EA, "EA"},
	{TK_WE, "WE"},
	{TK_F, "F"},
	{TK_C, "C"},
	{TK_OTHER, NULL}
	};

	return (tokens);
}

static t_tok_type	compare_resource_token(char *line)
{
	t_tokens	*tokens;

	tokens = get_resources_tokens();
	while (token->line)
	{
		if (!ft_strncmp(line, token->line, ft_strlen(token->line)))
			return (token->type);
	}
	return (token->type);
}

static int	is_map_line(char *line)
{
	while (*line)
	{
		if (!ft_strchr(MAP_ELEMENTS, *line))
			return (0);
		line++;
	}
	return (1);
}

t_tok_type	compare_tokens(char *line)
{
	while (ft_isspace(*line))
		line++;
	if (!*line)
		return (TK_NL);
	if (is_map_line(line))
		return (TK_MAP);
	return (compare_resource_token(line));
}
