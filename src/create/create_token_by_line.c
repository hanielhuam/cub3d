/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token_by_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:53:24 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/12 19:22:24 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	remove_line_end(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (len && line[len - 1] == '\n')
		line[--len] = '\0';
	if (len && line[len - 1] == '\r')
		line[len - 1] = '\0';
}

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
	remove_line_end(line);
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
