/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 20:56:09 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/03/30 19:59:14 by hmacedo-         ###   ########.fr       */
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

typedef struct s_file_game
{
	char	*file_name;
}			t_file_game;

int		argc_validation(int argc);

#endif
