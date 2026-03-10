/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:46:26 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/13 18:12:45 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	ft_dlstdelone(t_dlist *element, void (*del)(void*))
{
	if (!element)
		return ;
	del(element->content);
	free(element);
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

void	del_stck(void * content)
{
	free(content);
}

int	main(void)
{
	int	*nu;
	t_dlist *el;

	nu = newint_point(42);
	el = ft_dlstnew(nu);
	printf("next of el is %p\n", el->next);
	ft_dlstdelone(el, del_stck);
	printf("after delone\n");
	printf("next of el is %p\n", el->next);
	return (0);
}*/
