/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:57:17 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/04/28 20:01:39 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*dup_str(char *str)
{
	char	*result;

	result = ft_strdup(str);
	if (!result)
	{
		ft_dprintf(STDERR_FILENO, "Error: duplicating string\n");
		return (NULL);
	}
	return (result);
}
