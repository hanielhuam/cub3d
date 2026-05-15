/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_token_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 20:34:41 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/05/14 21:37:40 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	validate_token_order(t_list *tokens)
{
	while (tokens && ((t_token *)tokens->content)->type != TK_MAP)
		tokens = tokens->next;
	while (tokens && (((t_token *)tokens->content)->type == TK_MAP || \
			((t_token *)tokens->content)->type == TK_NL))
		tokens = tokens->next;
	if (!tokens)
		return (0);
	ft_dprintf(STDERR_FILENO, "Error: is not allow to have line after map\n");
	return (1);
}

static int	evaluate_count_elements(int element, int count)
{
	t_token	*resources;

	resources = get_resources_tokens();
	if (element >= 0 && element <= 5 && count != 1)
	{
		ft_dprintf(STDERR_FILENO, \
				"Error: should have only 1 %s in the .cub file\n", \
				resources[element].line);
		return (1);
	}
	if (element == 6 && count < 3)
	{
		ft_dprintf(STDERR_FILENO, "Error: there is no possible map\n");
		return (1);
	}
	if (element == 8 && count > 0)
	{
		ft_dprintf(STDERR_FILENO, "Error: there is a strange element\n");
		return (1);
	}
	return (0);
}

static int	*get_evaluate_count(t_list *tokens)
{
	int		*elements;
	t_token	*temp;

	elements = ft_calloc(8, sizeof(int));
	if (!elements)
	{
		ft_dprintf(STDERR_FILENO, "Error: unable to alloc elements count\n");
		return (NULL);
	}
	while (tokens)
	{
		temp = (t_token *)tokens->content;
		if (temp->type == TK_OTHER)
		{
			ft_dprintf(STDERR_FILENO, "Error: invalid line\n%s\n", temp->line);
			free(elements);
			return (NULL);
		}
		elements[temp->type]++;
		tokens = tokens->next;
	}
	return (elements);
}

static int	validate_elements_count(t_list *tokens)
{
	int		i;
	int		*elements;

	elements = get_evaluate_count(tokens);
	if (!elements)
		return (1);
	i = 0;
	while (i < 9)
	{
		if (evaluate_count_elements(i, elements[i]))
		{
			free(elements);
			return (1);
		}
		i++;
	}
	free(elements);
	return (0);
}

int	validate_token_list(t_list *tokens)
{
	if (validate_elements_count(tokens) || validate_token_order(tokens))
		return (1);
	return (0);
}
