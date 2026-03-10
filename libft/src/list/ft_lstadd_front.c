/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:05:11 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/24 19:23:13 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>

void	show_list(t_list *list);

void	show_node(t_list *node);

int	main(void)
{
	t_list	*list;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;

	node1 = ft_lstnew("Haniel");
	node2 = ft_lstnew("Huam");
	node3 = ft_lstnew("Macedo");
	node4 = ft_lstnew("Ferreira");
	node2->next = node3;
	node3->next = node4;
	list = node2;
	ft_lstadd_front(&list, NULL);
	show_list(list);
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
