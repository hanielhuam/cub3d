/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 19:36:14 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/09 21:16:31 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_token	*get_resources_tokens(void)
{
	static t_token	tokens[7] = {
	{TK_NO, "NO "},
	{TK_SO, "SO "},
	{TK_EA, "EA "},
	{TK_WE, "WE "},
	{TK_F, "F "},
	{TK_C, "C "},
	{TK_OTHER, NULL}
	};

	return (tokens);
}

static t_tok_type	compare_resource_token(char *line)
{
	t_token	*tokens;

	tokens = get_resources_tokens();
	while (tokens->line)
	{
		if (!ft_strncmp(line, tokens->line, ft_strlen(tokens->line)))
			return (tokens->type);
		tokens++;
	}
	return (tokens->type);
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

t_tok_type	compare_token(char *line)
{
	while (ft_isspace(*line))
		line++;
	if (!*line)
		return (TK_NL);
	if (is_map_line(line))
		return (TK_MAP);
	return (compare_resource_token(line));
}
