/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_constructor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 21:30:56 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/03 00:29:59 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**map_constructor(t_list *tokens, int map_lenght)
{
	char	*temp
	int 	count;
	char	**map;

	map = ft_calloc(map_lenght + 1, sizeof(char *));
	if (!map)
	{
		ft_dprintf(STDERR_FILENO, "Error: unable to alloc board map\n");
		return (NULL);
	}
	while (!tokens && ((t_token *)tokens->content)->type != TK_MAP)
		tokens = tokens->next;
	count = 0;
	while (!tokens && ((t_token *)tokens->content)->type == TK_MAP)
	{
		temp = dup_str(((t_token *)tokens->content)->line);
		if (!temp)
		{
			del_split(map);
			return (NULL);
		}
		map[count++] = temp;
		tokens = tokens->next;
	}
	return (map);
}
