/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stckclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:07:46 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/04/25 19:50:59 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stckclear(t_stack **stack, void (*del)(void *))
{
	t_stack	*init;
	t_stack	*temp;

	if (!*stack)
		return ;
	init = *stack;
	*stack = (*stack)->next;
	while (*stack != init)
	{
		temp = (*stack)->next;
		ft_stckdelone(*stack, del);
		*stack = temp;
	}
	ft_stckdelone(*stack, del);
	*stack = NULL;
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

void	print_t_stack(t_stack *element)
{
	printf("element->index = %d\n", element->index);
	printf("element->before = %p\n", element->before);
	printf("element->next = %p\n", element->next);
	printf("element->content = %d\n", *((int *)element->content));
}

void	print_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
	{
		printf("stack está nula\n");
		return ;
	}
	print_t_stack(*stack);
	temp = (*stack)->next;
	while (temp != *stack)
	{
		printf("\n");
		print_t_stack(temp);
		temp = temp->next;
	}
	printf("\n");
}

void	del_stck(void * content)
{
	free(content);
}

int	main(void)
{
	t_stack	**stack;
	t_stack *tmp;

	tmp = ft_stcknew(newint_point(42));
	stack = &tmp;
	ft_stckadd_front(stack, ft_stcknew(newint_point(24)));
	ft_stckadd_back(stack, ft_stcknew(newint_point(84)));
	print_stack(stack);
	ft_stckclear(stack, del_stck);
	printf("depois da ft_clear\n");
	print_stack(stack);
	return (0);
}*/
