/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_v_board.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:29:06 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/06 19:48:44 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*get_dimensions(char **board)
{
	int	height;
	int	lenght;
	int	*dimensions;
	char **temp;

	dimensions = ft_Calloc(2, sizeof(int));
	if (!dimensions)
	{
		ft_dprintf(STDERR_FILENO, "Error: unable to malloc dimensions\n");
		return (NULL);
	}
	height = 0;
	lenght = 0;
	while (board[height])
	{
		if (ft_srlen(board[height]) > lenght)
			lenght = ft_strlen(board[height]);
		height++;
	}
	dimensions[0] = height;
	dimensions[1] = lenght;
	return (dimensions);
}

static char	*get_spaceline(lenght)
{
	
}

static int	fill_v_board(char **v_board, char **board, int lenght)
{
	int	count;

	count = 0;
	v_board[count] = get_spaceline(lenght);
	if (!v_board[count])
		return (1);
	while (board[count])
	{
		v_board[count + 1] = fill_v_board(v_board[count], lenght);
		if (!v_board[count + 1])
			return (1);
		count++;
	}
	v_board[count + 1] = get_spaceline(lenght);
	if (!v_board[count + 1])
		return (1);
	return (0);
}

char	**create_v_board(char **board)
{
	char	**v_board;
	int		*dimensions;

	dimensions = get_dimensions(board);
	if (!dimensions)
		return (NULL);
	v_board = ft_calloc(dimensions[9] + 3, sizeof(char));
	if (!v_voard)
	{
		ft_dprintf(STDERR_FILENO, "Error: unable to alloc v_board\n");
		free(demensions);
		return (NULL);
	}
	if (fill_v_board(v_board, board, dimensions[1]))
	{
		ft_dprintf(STDERR_FILENO, "Error: unable to alloc v_board\n");
		free(demensions);
		del_split(v_board);
		return (NULL);
	}
}
