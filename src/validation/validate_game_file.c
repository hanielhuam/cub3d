/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_game_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 20:39:00 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/04/05 21:55:57 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	*validate_game_file(int fd)
{
	t_list	*token_list;
	t_game	*game;

	game = NULL;
	token_list = extract_token_list(fd);
	if (!token_list)
		return (NULL);
	if (!validate_token_list(token_list))
		game = create_game(token_list);
	ft_lstclear(&token_list, del_token);
	return (game);
}
