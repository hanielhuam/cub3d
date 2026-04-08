/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_token_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 19:34:46 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/04/07 21:19:27 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	add_token2list(t_list **list, char *line)
{
	t_list	*temp;
	t_token	*token;

	token = create_token_by_line(line);
	if (!token)
		return (1);
	temp = ft_lstnew(token);
	if (!temp)
	{
		del_token(token);
		return (1);
	}
	ft_lstadd_back(list, temp);
	return (0);
}

t_list	*extract_token_list(int fd)
{
	t_list	*list;
	char	*line;

	list = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (!add_token2list(&list, line))
		{
			ft_lstclear(&list, del_token);
			free(line);
			return (NULL);
		}
		free(line);
	}
	return (list);
}
