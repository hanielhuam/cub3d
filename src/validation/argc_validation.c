/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 19:54:29 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/03/30 20:00:46 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	argc_validation(int argc)
{
	if (argc != 2)
	{
		ft_dprintf(STDERR_FILENO, "Error: too few arguments\n");
		return (1);
	}
	return (0);
}
