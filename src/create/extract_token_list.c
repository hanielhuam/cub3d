/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_token_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 19:34:46 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/04/06 21:31:16 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list	extract_token_list(int fd)
{
	t_list	*list;
	char	*line;
	t_token	*token;

	list = NULL;
	line = get_next_line(fd);
	while (line)
	{
		token = create_token_by_line(line);
		if (!token && list)
		{
			lstclear(&list, del_token
		}
			
	}
	return (list);
}
