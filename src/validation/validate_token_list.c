/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_token_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 20:34:41 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/04/13 21:16:09 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	validate_token_order(t_list *tokens)
{
	
}

static 

static int	validate_elements_count(t_list *tokens)
{
	int		i;
	int		elements[9];
	t_token	temp;

	elements = {0};
	while (tokens)
	{
		temp = (t_token *)tokens->content;
		elements[tenp->type]++;
		tokens = tokens->next;
	}
	i = 0;
	while (i < 9)
	{
		evaluate_count_elements();
		i++;
	}
}

int	validate_token_list(t_list *tokens)
{
	if (validate_elements_count(tokens) || vvalidate_token_order(tokens))
		return (1);
	return (0);
}
