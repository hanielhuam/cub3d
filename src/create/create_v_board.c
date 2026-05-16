/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_v_board.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:29:06 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/14 19:48:01 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*get_dimensions(char **board)
{
	int	height;
	int	lenght;
	int	*dimensions;

	dimensions = ft_calloc(2, sizeof(int));
	if (!dimensions)
	{
		ft_dprintf(STDERR_FILENO, "Error: unable to malloc dimensions\n");
		return (NULL);
	}
	height = 0;
	lenght = 0;
	while (board[height])
	{
		if ((int)ft_strlen(board[height]) > lenght)
			lenght = ft_strlen(board[height]);
		height++;
	}
	dimensions[0] = height;
	dimensions[1] = lenght;
	return (dimensions);
}

static char	*get_spaceline(int lenght)
{
	int		count;
	char	*space_line;

	space_line = ft_calloc(lenght + 1, sizeof(char));
	if (!space_line)
	{
		ft_dprintf(STDERR_FILENO, "Error: unable to alloc space_line\n");
		return (NULL);
	}
	count = 0;
	while (count < lenght)
		space_line[count++] = ' ';
	return (space_line);
}

static char	*fill_v_board_line(char *line, int lenght)
{
	int		count;
	int		line_lenght;
	char	*result;

	result = ft_calloc(lenght + 1, sizeof(char));
	if (!result)
	{
		ft_dprintf(STDERR_FILENO, "Error: unable to alloc v_board_line\n");
		return (NULL);
	}
	count = 0;
	result[count] = ' ';
	count++;
	line_lenght = ft_strlen(line);
	while (count <= line_lenght)
	{
		result[count] = line[count - 1];
		count++;
	}
	while (count < lenght)
		result[count++] = ' ';
	return (result);
}

static int	fill_v_board(char **v_board, char **board, int lenght)
{
	int	count;

	count = 0;
	v_board[count] = get_spaceline(lenght + 2);
	if (!v_board[count])
		return (1);
	while (board[count])
	{
		v_board[count + 1] = fill_v_board_line(board[count], lenght + 2);
		if (!v_board[count + 1])
			return (1);
		count++;
	}
	v_board[count + 1] = get_spaceline(lenght + 2);
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
	v_board = ft_calloc(dimensions[0] + 3, sizeof(char *));
	if (!v_board)
	{
		ft_dprintf(STDERR_FILENO, "Error: unable to alloc v_board\n");
		free(dimensions);
		return (NULL);
	}
	if (fill_v_board(v_board, board, dimensions[1]))
	{
		ft_dprintf(STDERR_FILENO, "Error: unable to alloc v_board\n");
		free(dimensions);
		del_split(v_board);
		return (NULL);
	}
	free(dimensions);
	return (v_board);
}
