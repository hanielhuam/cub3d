/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treefar_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 23:03:59 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/14 20:02:52 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tree.h"

t_tree	*ft_treefar_left(t_tree *tree)
{
	if (!tree)
		return (NULL);
	if (!tree->left)
		return (tree);
	return (ft_treefar_left(tree->left));
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
	t_tree	*cabeça;
	t_tree	*left;
	t_tree	*right;

	cabeça = ft_treenew(ft_strdup("Huam"));
	left = ft_treenew(ft_strdup("Haniel"));
	right = ft_treenew(ft_strdup("Macedo"));
	printf("primeiro print, trazer a própria cabeça\n");
	show_t_tree(ft_treefar_left(cabeça));
	cabeça->left = left;
	cabeça->right = right;
	left->prev = cabeça;
	right->prev = cabeça;
	printf("segundo print, mestrar como está a estrutura\n");
	show_tree(cabeça);
	printf("ultimo print, trazer o nó left\n");
	show_t_tree(ft_treefar_left(cabeça));
	return (0);
}*/
