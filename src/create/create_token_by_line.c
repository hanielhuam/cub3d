/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token_by_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:53:24 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/04/15 23:41:22 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_token	*create_token_by_line(char *line)
{
	t_token	*token;
	char	*dup;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
	{
		ft_dprintf(STDERR_FILENO, "Error: Unable to malloc token\n");
		return (NULL);
	}
	dup = ft_strdup(line);
	if (!dup)
	{
		free(token);
		ft_dprintf(STDERR_FILENO, "Error: Unable to duplicate token string\n");
		return (NULL);
	}
	token->line = dup;
	token->type = compare_token(line);
	return (token);
}
