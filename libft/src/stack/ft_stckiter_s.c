/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stckiter_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:44:02 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/04/17 21:22:44 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stckiter_s(t_stack *stack, void (*f)(t_stack *))
{
	t_stack	*start;

	if (!stack)
		return ;
	f(stack);
	start = stack->next;
	while (start != stack)
	{
		f(start);
		start = start->next;
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

void	plusone(t_stack *node)
{
	node->index += 1;
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
	ft_stckiter_s(*stack, plusone);
	printf("depois da ft_stckiter\n");
	print_stack(stack);
	return (0);
}*/
