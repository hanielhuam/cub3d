/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 20:41:50 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/04 21:30:32 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	board_validator(char **board)
{
	char	**v_board;

	if (check_main_character(board))
		return (1);
	v_board = creat_v_board(board);
	if (check_integrity(v_board))
	{
		free(v_board);
		return (1);
	}
	free(v_board);
	return (0);
}
