/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stcksize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:07:14 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/05/01 21:19:03 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stcksize(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	i = 0;
	if (!stack || !*stack)
		return (i);
	i++;
	temp = (*stack)->next;
	while (temp != *stack)
	{
		i++;
		temp = temp->next;
	}
	return (i);
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

	if (stack && *stack)
	{
		print_t_stack(*stack);
		temp = (*stack)->next;
		while (temp != *stack)
		{
			printf("\n");
			print_t_stack(temp);
			temp = temp->next;
		}
	}
	printf("\n");
}

int	main(void)
{
	t_stack	**stack;

	stack = NULL;
	printf("primeiro print\n");
	printf("size of stack = %d\n", ft_stcksize(stack));
	print_stack(stack);
	stack = ft_calloc(1, sizeof(t_stack *));
	printf("segundo  print\n");
	printf("size of stack = %d\n", ft_stcksize(stack));
	print_stack(stack);
	*stack = ft_stcknew(newint_point(42));
	printf("terceiro print\n");
	printf("size of stack = %d\n", ft_stcksize(stack));
	print_stack(stack);
	ft_stckadd_front(stack, ft_stcknew(newint_point(24)));
	printf("quarto print\n");
	printf("size of stack = %d\n", ft_stcksize(stack));
	print_stack(stack);
	ft_stckadd_front(stack, ft_stcknew(newint_point(84)));
	printf("quinto print\n");
	printf("size of stack = %d\n", ft_stcksize(stack));
	print_stack(stack);
		return (0);
}*/
