/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stckmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:17:26 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/04/21 18:22:46 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack	*ft_stckmap(t_stack *stack, void *(*f)(void *), void (*del)(void *))
{
	t_stack	*start;
	t_stack	*temp;
	t_stack	*newstack;

	if (ft_stckcheck(&stack))
		return (NULL);
	newstack = ft_stcknew(f(stack->content));
	if (!newstack)
		return (NULL);
	start = stack->next;
	while (start != stack)
	{
		temp = ft_stcknew(f(start->content));
		if (!temp)
		{
			ft_stckclear(&newstack, del);
			return (NULL);
		}
		ft_stckadd_back(&newstack, temp);
		start = start->next;
	}
	return (newstack);
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

void	*plusone(void * content)
{
	int	*result;

	result = malloc(sizeof(int) * 1);
	*result = *((int *)content) + 1;
	return ((void *)result);
}

int	main(void)
{
	t_stack	**stack;
	t_stack *tmp;
	t_stack *result;

	tmp = ft_stcknew(newint_point(42));
	stack = &tmp;
	ft_stckadd_front(stack, ft_stcknew(newint_point(24)));
	ft_stckadd_back(stack, ft_stcknew(newint_point(84)));
	print_stack(stack);
	result = ft_stckmap(*stack, plusone, free);
	printf("depois da ft_stckiter\n");
	print_stack(&result);
	return (0);
}*/
