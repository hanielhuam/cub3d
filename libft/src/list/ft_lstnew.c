/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:07:54 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/26 08:01:02 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*
#include <stdio.h>

void	show_node(t_list *node);

int	main(void)
{
	char	*str;
	t_list	*node;

	str = ft_strdup("Haniel");
	node = ft_lstnew(str);
	show_node(node);
	return (0);
}

void    show_node(t_list *node)
{
	printf("content = %s\n", (char *) node->content);
	printf("next = %p", node->next);
}*/