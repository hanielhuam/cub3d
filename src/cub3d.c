/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 21:09:54 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/08 23:28:04 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc_validation(argc))
		return (1);
	game = create_validate_game(argv[1]);
	if (!game)
		return (1);
	del_game(game);
	return (0);
}
