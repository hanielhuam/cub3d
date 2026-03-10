/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:07:14 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/12 21:39:07 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

int	ft_dlstsize(t_dlist *list)
{
	int		i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
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
	while (list)
	{
		print_t_dlist(list);
		list = list->next;
	}
}

int	main(void)
{
	t_dlist	**list;

	list = ft_calloc(1, sizeof(t_dlist *));
	*list = ft_dlstnew(newint_point(42));
	printf("primeiro print\n");
	printf("size of list = %d\n", ft_dlstsize(*list));
	print_dlist(*list);
	ft_dlstadd_front(list, ft_dlstnew(newint_point(24)));
	printf("segundo print\n");
	printf("size of list = %d\n", ft_dlstsize(*list));
	print_dlist(*list);
	ft_dlstadd_front(list, ft_dlstnew(newint_point(84)));
	printf("terceiro print\n");
	printf("size of list = %d\n", ft_dlstsize(*list));
	print_dlist(*list);
		return (0);
}*/
