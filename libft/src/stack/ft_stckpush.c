/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stckpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:52:19 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/05/01 21:06:28 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

static void	minus_one(t_stack *node)
{
	node->index -= 1;
}

static void	plus_one(t_stack *node)
{
	node->index += 1;
}

static t_stack	*handle_stack_from(t_stack **stack_from)
{
	t_stack	*temp;

	temp = *stack_from;
	if (ft_stcksize(stack_from) == 1)
		*stack_from = NULL;
	else
	{
		*stack_from = (*stack_from)->next;
		(*stack_from)->before = temp->before;
		(*stack_from)->before->next = *stack_from;
		ft_stckiter_s(*stack_from, minus_one);
	}
	return (temp);
}

static void	handle_stack_to(t_stack *new_node, t_stack **stack_to)
{
	new_node->index = 0;
	if (!ft_stcksize(stack_to))
	{
		new_node->next = new_node;
		new_node->before = new_node;
		*stack_to = new_node;
		return ;
	}
	ft_stckiter_s(*stack_to, plus_one);
	new_node->next = *stack_to;
	new_node->before = (*stack_to)->before;
	new_node->before->next = new_node;
	new_node->next->before = new_node;
	*stack_to = new_node;
}

void	ft_stckpush(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*temp;

	if (!stack_from || !*stack_from || !stack_to)
		return ;
	temp = handle_stack_from(stack_from);
	handle_stack_to(temp, stack_to);
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
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = ft_calloc(1, sizeof(t_stack *));
	*stack_a = ft_stcknew(newint_point(11));
	ft_stckadd_front(stack_a, ft_stcknew(newint_point(10)));
	//ft_stckadd_back(stack_a, ft_stcknew(newint_point(12)));
	printf("STACK A\n");
	print_stack(stack_a);
	stack_b = ft_calloc(1, sizeof(t_stack *));
	// *stack_b = ft_stcknew(newint_point(111));
	//ft_stckadd_front(stack_b, ft_stcknew(newint_point(110)));
	//ft_stckadd_back(stack_b, ft_stcknew(newint_point(112)));
	printf("STACK B\n");
	print_stack(stack_b);
	printf("\ndepois da ft_stckpush\n");
	ft_stckpush(stack_a, stack_b);
	printf("STACK A\n");
	print_stack(stack_a);
	printf("STACK B\n");
	print_stack(stack_b);
	return (0);
}*/
