/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:04:55 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/12 20:19:43 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_dlstnew(void *content)
{
	t_dlist	*element;

	element = ft_calloc(1, sizeof(t_dlist));
	if (!element)
		return (NULL);
	element->content = content;
	element->next = NULL;
	element->before = NULL;
	return (element);
}
/*
#include <stdio.h>

void	print_t_dlist(t_dlist *element)
{
	printf("element->before = %p\n", element->before);
	printf("element->next = %p\n", element->next);
	printf("element->content = %d\n", *((int *)element->content));
}

int	main(void)
{
	int	nu;

	nu = 42;
	print_t_dlist(ft_dlstnew(&nu));
	return (0);
}*/
