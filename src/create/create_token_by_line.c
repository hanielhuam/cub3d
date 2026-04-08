/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token_by_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:53:24 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/04/07 21:19:21 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_token	*create_token_by_line(char *line)
{
	t_token	*token;
	char	*dup;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
		return (NULL);
	dup = ft_strdup(line);
	if (!dup)
	{
		free(token);
		return (NULL);
	}
	token->line = dup;
	compare_token();
}
