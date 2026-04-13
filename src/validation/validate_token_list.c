/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_token_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 20:34:41 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/04/12 21:29:43 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	validate_token_order(t_list *tokens)
{

}

static int	validate_duplication(t_list *tokens)
{
	
}

static int	validate_missing_element(t_list *tokens)
{
	
}

int	validate_token_list(t_list *tokens)
{
	if (validate_token_order(tokens) || validate_duplication(tokens) \
			|| validate_missing_element(tokens))
		return (1);
	return (0);
}
