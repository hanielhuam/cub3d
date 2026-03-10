/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 20:37:37 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/19 23:21:19 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tree.h"

void	ft_treeclear(t_tree **tree, void (*del)(void *))
{
	t_tree	*left;
	t_tree	*right;

	if (!*tree)
		return ;
	left = (*tree)->left;
	right = (*tree)->right;
	ft_treedelone(*tree, del);
	ft_treeclear(&left, del);
	ft_treeclear(&right, del);
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
	ft_treeclear(tree, free);
	free(tree);
	return (0);
}*/
