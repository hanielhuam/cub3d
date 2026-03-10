/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 21:28:25 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/16 20:44:24 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TREE_H
# define FT_TREE_H

# include "libft.h"

typedef struct s_tree
{
	void			*content;
	struct s_tree	*prev;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

t_tree	*ft_treenew(void *content);
t_tree	*ft_treefar_left(t_tree *tree);
t_tree	*ft_treefar_right(t_tree *tree);
void	ft_treeadd_left(t_tree **tree, t_tree *new);
void	ft_treeadd_right(t_tree **tree, t_tree *new);
void	ft_treedelone(t_tree *element, void (*del)(void *));
void	ft_treeclear(t_tree **tree, void (*del)(void *));
void	ft_treeiter(t_tree *node, void (*f)(void *));

#endif 
