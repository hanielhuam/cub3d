/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:55:51 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/26 02:10:47 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	lst = NULL;
}
/*
#include <stdio.h>

void	show_list(t_list *list);

void	show_node(t_list *node);

void	show_delnode(t_list *node, char *content);

int	main(void)
{
	char	*name;
	char	*second_name;
	t_list	*node1;
	t_list	*node2;

	name = ft_strdup("Haniel");
	second_name = ft_strdup("Huam");
	node1 = ft_lstnew(name);
	node2 = ft_lstnew(second_name);
	ft_lstadd_back(&node1, node2);
	show_list(node1);
	ft_lstclear(&node1, free);
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
}

void	show_delnode(t_list *node, char *content)
{
	printf("addres of node->content %p\n", node->content);
	printf("addres of content %p\n", content);
	printf("content %s\n", content);
}*/
