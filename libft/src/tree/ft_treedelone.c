/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treedelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 20:19:27 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/14 20:35:33 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tree.h"

void	ft_treedelone(t_tree *element, void (*del)(void *))
{
	if (!element)
		return ;
	del(element->content);
	free(element);
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

void	show_tree(t_tree *tree)
{
	if (!tree)
	{
		printf("Não tem nada nesse nó da árvore\n");
		return ;
	}
	show_t_tree(tree);
	printf("conteúdo do filho à esquerda\n");
	show_tree(tree->left);
	printf("conteúdo do filho à direita\n");
	show_tree(tree->right);
}

int	main(void)
{
	t_tree	*tree;

	tree = ft_treenew("Haniel");
	show_t_tree(tree);
	ft_treedelone(tree, free);
	printf("segundo print, vai mostrar o nó vazio\n");
	show_t_tree(tree);
	return (0);
}*/
