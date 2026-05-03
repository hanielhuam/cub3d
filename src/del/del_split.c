/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 16:47:16 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/02 18:43:45 by hmacedo-         ###   ########.fr       */
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
		*split = NULL;
	}
	free(temp);
}
