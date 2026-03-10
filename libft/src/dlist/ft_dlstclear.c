/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:07:46 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/13 19:23:19 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	ft_dlstclear(t_dlist **list, void (*del)(void *))
{
	t_dlist	*temp;

	while (*list)
	{
		temp = (*list)->next;
		ft_dlstdelone(*list, del);
		*list = temp;
	}
	*list = NULL;
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
	printf("element->content = %s\n", (char *)element->content);
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

void	del_list(void * content)
{
	free(content);
}

int	main(void)
{
	t_dlist	**list;

	list = ft_calloc(1, sizeof(t_dlist *));
	ft_dlstadd_back(list, ft_dlstnew(ft_strdup("haniel")));
	ft_dlstadd_back(list, ft_dlstnew(ft_strdup("Huam")));
	print_dlist(*list);
	ft_dlstclear(list, del_list);
	print_dlist(*list);
	free(list);
	return (0);
}*/
