/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 20:56:09 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/28 18:47:45 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "ft_printf.h"
# include "ft_tree.h"
# include "ft_list.h"
# include "ft_dlist.h"
# include "get_next_line.h"
# include "mlx.h"

# define MAP_ELEMENTS "01 NSWE"
# define WIDITH 1280
# define HEIGHT 720

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

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_lenght;
	int		endian;
}			t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	t_img	*screen;
}			t_mlx;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}			t_player;

typedef struct s_game
{
	char		**board;
	t_assets	*assets;
	t_mlx		*mlx;
	t_player	*player;
}				t_game;

int				argc_validation(int argc);
t_game			*create_validate_game(char *file_nema);
int				validate_open_file(char *file_game);
t_game			*validate_game_file(int fd);
int				validate_game(t_game *game);
int				validate_token_list(t_list *tokens);
t_tok_type		compare_token(char *line);
int				color_validation(char *line);
int				check_file(char *file);
int				board_validator(char **board);
void			del_assets(t_assets *assests);
void			del_game(t_game *game);
void			del_token(void *token);
void			del_split(char **split);
void			del_mlx(t_mlx *mlx);
t_list			*extract_token_list(int fd);
unsigned char	*extract_colors(char *line);
t_token			*get_resources_tokens(void);
t_token			*create_token_by_line(char *line);
t_game			*create_game(t_list *tokens);
char			**create_v_board(char **board);
int				assign_assets(t_game *game, t_list *tokens);
char			*dup_str(char *str);
int				no_texture_constructor(t_game *game, char *line);
int				so_texture_constructor(t_game *game, char *line);
int				ea_texture_constructor(t_game *game, char *line);
int				we_texture_constructor(t_game *game, char *line);
int				floor_color_constructor(t_game *game, char *line);
int				ceiling_color_constructor(t_game *game, char *line);
char			**map_constructor(t_list *tokens, int board_lenght);
int				configure_game(t_game *game);
int				config_player(t_game *game);
int				close_window(t_game *game);
void			run(t_game *game);

#endif
