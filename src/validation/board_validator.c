/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 20:41:50 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/06 19:48:57 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_player(char **board)
{
	int	i;
	int j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (board[i])
	{
		while (board[i][j])
		{
			if (ft_strchr("NSEW", board[i][j]))
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	if (count == 1)
		return (0);
	ft_dprintf(STDERR_FILENO, "Error: player apears %d times on the board\n");
	return (1);
}

static char	**create_v_board(board)
{
	
}

int	board_validator(char **board)
{
	char	**v_board;

	if (check_player(board))
		return (1);
	v_board = create_v_board(board);
	if (check_integrity(v_board))
	{
		free(v_board);
		return (1);
	}
	free(v_board);
	return (0);
}
