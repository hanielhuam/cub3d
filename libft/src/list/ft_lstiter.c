/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 01:50:57 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/26 03:19:40 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
#include <stdio.h>

void	show_list(t_list *list);

void	show_node(t_list *node);

void	show_content(void *);

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
	ft_lstiter(node1, show_content);
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

void	show_content(void *content)
{
	printf("show content = %s\n", (char *)content);
}*/
