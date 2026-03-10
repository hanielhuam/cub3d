/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:09:40 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/12 22:03:08 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_dlstlast(t_dlist *list)
{
	if (!list)
		return (list);
	while (list->next)
		list = list->next;
	return (list);
}
/*
#include <stdio.h>

int     *newint_point(int nu)
{
        int     *nup;

        nup = ft_calloc(1, sizeof(int));
        *nup = nu;
        return (nup);
}

void    print_t_dlist(t_dlist *element)
{
        printf("element->before = %p\n", element->before);
        printf("element->next = %p\n", element->next);
        printf("element->content = %s\n", ((char *)element->content));
}

void    print_dlist(t_dlist *list)
{
	while (list)
	{
		print_t_dlist(list);
		list = list->next;
	}
}

int     main(void)
{
	t_dlist	*node1;
	t_dlist	*node2;
	t_dlist	*node3;
	t_dlist	*node4;

	node1 = ft_dlstnew("Haniel");
	node2 = ft_dlstnew("Huam");
	node3 = ft_dlstnew("Macedo");
	node4 = ft_dlstnew("Ferreira");
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->before = node3;
	node3->before = node2;
	node2->before = node1;
	print_t_dlist(ft_dlstlast(node1));
	node2->next = NULL;
	print_t_dlist(ft_dlstlast(node1));

	return (0);
}
*/
