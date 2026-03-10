/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:49:27 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/27 18:43:52 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	temp = ft_lstlast(*lst);
	if (temp)
		temp->next = new;
	else
		*lst = new;
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
	ft_lstadd_back(&node1, node2);
	ft_lstadd_back(&node1, node3);
	ft_lstadd_back(&node1, node4);
	show_list(node1);
	ft_lstadd_back(&node3, NULL);
	show_list(node1);

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
