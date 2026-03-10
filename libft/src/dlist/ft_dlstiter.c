/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:09:17 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/13 19:35:43 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	ft_dlstiter(t_dlist *list, void (*f)(void *))
{
	while (list)
	{
		f(list->content);
		list = list->next;
	}
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

void	plusone(void * content)
{
	*((int *)content) += 1;
}

int	main(void)
{
	t_dlist	**list;

	list = ft_calloc(1, sizeof(t_dlist *));
	ft_dlstadd_back(list, ft_dlstnew(newint_point(42)));
	ft_dlstadd_front(list, ft_dlstnew(newint_point(24)));
	ft_dlstadd_back(list, ft_dlstnew(newint_point(84)));
	print_dlist(*list);
	ft_dlstiter(*list, plusone);
	printf("depois da ft_dlstiter\n");
	print_dlist(*list);
	return (0);
}*/
