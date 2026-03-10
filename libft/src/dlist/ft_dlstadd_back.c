/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:29:06 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/12 23:18:15 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	ft_dlstadd_back(t_dlist **list, t_dlist *new)
{
	t_dlist	*temp;

	if (!new)
		return ;
	temp = ft_dlstlast(*list);
	if (temp)
	{
		temp->next = new;
		new->before = temp;
	}
	else
		*list = new;
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
	ft_dlstadd_back(list, ft_dlstnew(newint_point(24)));
	printf("primeiro print\n");
	print_dlist(*list);
	ft_dlstadd_back(list, ft_dlstnew(newint_point(42)));
	printf("segundo print\n");
	print_dlist(*list);
	ft_dlstadd_back(list, ft_dlstnew(newint_point(84)));
	printf("terceiro print\n");
	print_dlist(*list);
	return (0);
}*/
