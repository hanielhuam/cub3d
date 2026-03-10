/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:13:40 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/25 19:53:22 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}
/*
#include <stdio.h>

void	show_list(t_list *list);

void	show_node(t_list *node);

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
	show_node(node1);
	show_node(node2);
	ft_lstdelone(node1, free);
	printf("adress of content = %p\n", node1);
	printf("content = %s\n", name);
	show_node(node2);
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
