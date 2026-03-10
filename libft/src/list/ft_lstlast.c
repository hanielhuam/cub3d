/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:30:06 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/27 18:35:35 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>

void	show_list(t_list *list);

void	show_node(t_list *node);

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;

	node1 = ft_lstnew("Haniel");
	node2 = ft_lstnew("Huam");
	node3 = ft_lstnew("Macedo");
	node4 = ft_lstnew("Ferreira");
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	show_node(ft_lstlast(node1));
	node2->next = NULL;
	show_node(ft_lstlast(node1));

	return (0);
}

void    show_list(t_list *list)
{
	while (list)
	{
		show_node(list);
		list = list->next;
	}	
}

void    show_node(t_list *node)
{
	printf("adrees of content = %p\n", node);
	printf("content = %s\n", (char *) node->content);
	printf("next = %p\n", node->next);
}*/
