/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:33:42 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/16 20:42:44 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tree.h"

void	ft_treeiter(t_tree *node, void (*f)(void *))
{
	if (!node)
		return ;
	ft_treeiter(node->left, f);
	f(node->content);
	ft_treeiter(node->right, f);
}
