/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:11:06 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/12 20:41:06 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	ft_dlstadd_front(t_dlist **list, t_dlist *new)
{
	if (!new)
		return ;
	if (*list)
		(*list)->before = new;
	new->next = *list;
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

void	print_list(t_dlist **list)
{
	t_dlist	*temp;

	print_t_dlist(*list);
	temp = (*list)->next;
	while (temp)
	{
		printf("\n");
		print_t_dlist(temp);
		temp = temp->next;
	}
	printf("\n");
}

int	main(void)
{
	t_dlist	**list;
	t_dlist *tmp;

	tmp = ft_dlstnew(newint_point(42));
	list = &tmp;
	printf("primeiro print\n");
	print_list(list);
	ft_dlstadd_front(list, ft_dlstnew(newint_point(24)));
	printf("segundo print\n");
	print_list(list);
	ft_dlstadd_front(list, ft_dlstnew(newint_point(84)));
	printf("terceiro print\n");
	print_list(list);
	return (0);
}*/