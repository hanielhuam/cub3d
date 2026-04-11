/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token_by_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:53:24 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/04/10 22:56:16 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_tok_type	compare_token(char *line)
{
	

	while (ft_isspace(*line))
		line++;
	
}

t_token	*create_token_by_line(char *line)
{
	t_token	*token;
	char	*dup;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
	{
		ft_dprintf(STDERR_FILENO, "Unable to malloc token\n");
		return (NULL);
	}
	dup = ft_strdup(line);
	if (!dup)
	{
		free(token);
		ft_dprintf(STDERR_FILENO, "Unable to duplicate token string\n");
		return (NULL);
	}
	token->line = dup;
	token->type = compare_token(line);
}
