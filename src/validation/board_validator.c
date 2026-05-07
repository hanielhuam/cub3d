/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 20:41:50 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/07 20:11:08 by hmacedo-         ###   ########.fr       */
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

static int	check_integruty(char **board, int x, int y, int lenght)
{
	if (x < 0 || y < 0 || x >= lenght)
		return (0);
	if (ft_strchr("WSNEDA0", board[x][y]))
		return (1);
	if (board[x][y] == '1' || board[x][y] == '\0' || board[x][y] == 'X')
		return (0);
	if (board[x][y] == ' ')
		board[x][y] = 'X';
	if (check_integruty(board, x + 1, y) || check_integruty(board, x - 1, y) \
			|| check_integruty(board, x, y + 1) \
			|| check_integruty(board, x, y - 1))
		return (1);
	return (0);
}

static int get_lenght(board)
{
	int	count;

	count = 0;
	while (board[count])
		count++;
	return (count);
}

int	board_validator(char **board)
{
	int		count;
	char	**v_board;

	if (check_player(board))
		return (1);
	v_board = create_v_board(board);
	if (!v_board)
		return (1);
	lenght = get_lenght(board);
	if (check_integrity(v_board, 0, 0, lenght))
	{
		del_split(v_board);
		return (1);
	}
	del_split(v_board);
	return (0);
}
