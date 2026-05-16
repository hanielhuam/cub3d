/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 16:47:16 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/15 21:37:54 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	del_split(char **split)
{
	char	**temp;

	temp = split;
	while (*split)
	{
		free(*split);
		*split++ = NULL;
	}
	free(temp);
}
