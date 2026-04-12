/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 20:56:09 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/04/11 21:53:27 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include "ft_printf.h"
# include "ft_tree.h"
# include "ft_list.h"
# include "ft_dlist.h"
# include "get_next_line.h"

# define MAP_ELEMENTS "01 NSWE"

typedef enum e_tok_type
{
	TK_NO,
	TK_SO,
	TK_EA,
	TK_WE,
	TK_F,
	TK_C,
	TK_MAP,
	TK_NL,
	TK_OTHER
}	t_tok_type;

typedef struct s_token
{
	t_tok_type	type;
	char		*line;
}				t_token;

typedef struct s_assets
{
	char			*no_texture;
	char			*so_texture;
	char			*we_texture;
	char			*ea_texture;
	unsigned char	*ceiling_color;
	unsigned char	*floor_color;
}					t_assets;

typedef struct s_game
{
	char		**board;
	t_assets	*assets;
}			t_game;

int		argc_validation(int argc);
t_game	*create_validate_game(char *file_nema);
int		validate_open_file(char *file_game);
t_game	*validate_game_file(int fd);
char	validate_game(t_game *game);
void	del_assets(t_assets *assests);
void	del_board(char **board);
void	del_game(t_game *game);
void	del_token(void *token);
t_list	*extract_token_list(int fd);
t_token *create_token_by_line(char *line);

#endif
