/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 02:19:06 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/26 06:26:49 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*maplst;
	t_list	*tmp;
	size_t	sz;

	sz = ft_lstsize(lst);
	maplst = ft_lstnew(f(lst->content));
	if (!maplst)
	{
		ft_lstclear(&maplst, del);
		return (NULL);
	}
	lst = lst->next;
	sz--;
	while (sz--)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&maplst, del);
			return (NULL);
		}
		ft_lstadd_back(&maplst, tmp);
		lst = lst->next;
	}
	return (maplst);
}
/*
#include <stdio.h>

void	show_list(t_list *list);

void	show_node(t_list *node);

void	show_content(void *);

void	*to_upper(void *);

int	main(void)
{
	char	*name;
	char	*second_name;
	t_list	*node1;
	t_list	*node2;
	t_list	*maplst;

	name = ft_strdup("haniel");
	second_name = ft_strdup("huam");
	node1 = ft_lstnew(name);
	node2 = ft_lstnew(second_name);
	ft_lstadd_back(&node1, node2);
	show_list(node1);
	maplst = ft_lstmap(node1, to_upper, free);
	show_list(maplst);
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
}

void	*to_upper(void *content)
{
	size_t	sz;
	char	*str;
	
	sz = ft_strlen((char *) content);
	str = (char *)ft_calloc(sz, sizeof(char));
	while (sz--)
		str[sz] = ((char *)content)[sz] - 32;
	return ((void *)str);
}*/
