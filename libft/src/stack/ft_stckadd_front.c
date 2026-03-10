/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stckadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:11:06 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/04/21 18:16:12 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stckadd_front(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!stack || !(*stack) || !new)
		return ;
	new->index = 0;
	new->next = *stack;
	new->before = (*stack)->before;
	(*stack)->before->next = new;
	(*stack)->before = new;
	*stack = new;
	temp = new->next;
	while (temp != *stack)
	{
		temp->index += 1;
		temp = temp->next;
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
	t_stack *tmp;

	tmp = ft_stcknew(newint_point(42));
	stack = &tmp;
	printf("primeiro print");
	print_stack(stack);
	ft_stckadd_front(stack, ft_stcknew(newint_point(24)));
	printf("segundo print\n");
	print_stack(stack);
	ft_stckadd_front(stack, ft_stcknew(newint_point(84)));
	printf("terceiro print\n");
	print_stack(stack);
	return (0);
}*/
