/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stckdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:46:26 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/04/12 19:46:15 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stckdelone(t_stack *element, void (*del)(void*))
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
	t_stack *el;

	nu = newint_point(42);
	el = ft_stcknew(nu);
	printf("index of el is %d\nint of nu is %d\n", el->index, *nu);
	ft_stckdelone(el, del_stck);
	printf("after delone\n");
	printf("index of el is %d\nint of nu is %d\n", el->index, *nu);
	return (0);
}*/
