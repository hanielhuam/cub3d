/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 21:56:18 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/13 23:02:45 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tree.h"

t_tree	*ft_treenew(void *content)
{
	t_tree	*element;

	element = ft_calloc(1, sizeof(t_tree));
	if (!element)
		return (NULL);
	element->content = content;
	return (element);
}
/*
#include <stdio.h>

void	show_t_tree(t_tree *element)
{
	if (!element)
	{
		printf("element is NULL\n");
	}
	printf("element->content = %s\n", (char *)element->content);
	printf("element->prev = %p\n", element->prev);
	printf("element->left = %p\n", element->left);
	printf("element->right = %p\n", element->right);
}

int	main(void)
{
	show_t_tree(ft_treenew("Haniel"));
	show_t_tree(ft_treenew("Huam"));
	show_t_tree(ft_treenew("Macedo"));
	return (0);
}*/
