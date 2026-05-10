/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:32:22 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/09 20:45:32 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	del_token(void *content)
{
	t_token	*token;

	token = content;
	free(token->line);
	free(token);
}
