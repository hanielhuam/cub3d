/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stckswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:28:32 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/05/01 21:20:14 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stckswap(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->before = temp->before;
	(*stack)->before->next = *stack;
	temp->before = *stack;
	temp->next = (*stack)->next;
	temp->next->before = temp;
	(*stack)->next = temp;
	temp->index += 1;
	(*stack)->index -= 1;
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

int	main(void)
{
	t_stack	**stack;
	
	stack = ft_calloc(1, sizeof(t_stack *));
	*stack = ft_stcknew(newint_point(42));
	ft_stckadd_front(stack, ft_stcknew(newint_point(24)));
	ft_stckadd_back(stack, ft_stcknew(newint_point(84)));
	print_stack(stack);
	printf("depois da ft_stckswap\n");
	ft_stckswap(stack);
	print_stack(stack);
	ft_stckclear(stack, free);
	free(stack);
	return (0);
}*/
