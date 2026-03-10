/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:17:26 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/13 20:46:47 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_dlstmap(t_dlist *list, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*maplist;
	t_dlist	*tmp;

	maplist = NULL;
	while (list)
	{
		tmp = ft_dlstnew(f(list->content));
		if (!tmp)
		{
			ft_dlstclear(&maplist, del);
			return (NULL);
		}
		ft_dlstadd_back(&maplist, tmp);
		list = list->next;
	}
	return (maplist);
}
/*
#include <stdio.h>

int	*newint_point(int nu)
{
	int	*nup;

	nup = ft_calloc(1, sizeof(int));
	*nup = nu;
	return (nup);
}

void	print_t_dlist(t_dlist *element)
{
	printf("element->before = %p\n", element->before);
	printf("element->next = %p\n", element->next);
	printf("element->content = %d\n", *((int *)element->content));
}

void	print_dlist(t_dlist *list)
{
	if (!list)
	{
		printf("list está nula\n");
		return ;
	}
	while (list)
	{
		print_t_dlist(list);
		list = list->next;
	}
}

void	*plusone(void * content)
{
	int	*result;

	result = ft_calloc(1, sizeof(int));
	*result = *((int *)content) + 1;
	return ((void *)result);
}

int	main(void)
{
	t_dlist	**list;
	t_dlist *result;

	list = ft_calloc(1, sizeof(t_dlist *));
	ft_dlstadd_back(list, ft_dlstnew(newint_point(42)));
	ft_dlstadd_front(list, ft_dlstnew(newint_point(24)));
	ft_dlstadd_back(list, ft_dlstnew(newint_point(84)));
	print_dlist(*list);
	result = ft_dlstmap(*list, plusone, free);
	printf("depois da ft_dlstmap\n");
	print_dlist(result);
	return (0);
}*/
