/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeadd_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 20:05:30 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/19 23:20:15 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tree.h"

void	ft_treeadd_left(t_tree **tree, t_tree *element)
{
	t_tree	*far_left;

	if (!*tree)
	{
		*tree = element;
		return ;
	}
	far_left = ft_treefar_left(*tree);
	far_left->left = element;
	element->prev = far_left;
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
	t_tree	**tree;

	tree = ft_calloc(1, sizeof(t_tree *));
	printf("primeiro print, não vai mostrar nada\n");
	show_tree(ft_treefar_left(*tree));
	ft_treeadd_left(tree, ft_treenew(ft_strdup("Macedo")));
	printf("segundo print, vai mostrar o primeiro nó\n");
	show_tree(ft_treefar_left(*tree));
	ft_treeadd_left(tree, ft_treenew(ft_strdup("Huam")));
	ft_treeadd_left(tree, ft_treenew(ft_strdup("Haniel")));
	printf("terceiro print, vai mostrar o ultimo nome\n");
	show_tree(ft_treefar_left(*tree));
	return (0);
}*/
