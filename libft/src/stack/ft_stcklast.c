/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stcklast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:09:40 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/04/21 18:09:48 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

/*
description: this function check if the stack is ok
return value
0 = the stack is ok
1 = the stack doesnt begin with 0
2 = the stack doesnt end at the same element or isnt in the right order
*/

int	ft_stckcheck(t_stack **stack)
{
	t_stack	*temp;
	int		count;

	if (!stack || !*stack)
		return (0);
	if ((*stack)->index != 0)
		return (1);
	temp = (*stack)->before;
	if (temp->index == 0)
		return (0);
	count = temp->index;
	while (temp->index == count--)
		temp = temp->before;
	if (count < 0)
		return (0);
	return (2);
}
/*
#include <stdio.h>

int     *newint_point(int nu)
{
        int     *nup;

        nup = ft_calloc(1, sizeof(int));
        *nup = nu;
        return (nup);
}

void    print_t_stack(t_stack *element)
{
        printf("element->index = %d\n", element->index);
        printf("element->before = %p\n", element->before);
        printf("element->next = %p\n", element->next);
        printf("element->content = %d\n", *((int *)element->content));
}

void    print_stack(t_stack **stack)
{
        t_stack *temp;

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

int     main(void)
{
        t_stack **stack;
        t_stack *tmp;

        tmp = ft_stcknew(newint_point(42));
        stack = &tmp;
        printf("primeiro print");
        print_stack(stack);
		printf("the stack checker = %d\n", ft_stckcheck(stack));
        ft_stckadd_front(stack, ft_stcknew(newint_point(24)));
        printf("segundo print\n");
        print_stack(stack);
		printf("the stack checker = %d\n", ft_stckcheck(stack));
        ft_stckadd_front(stack, ft_stcknew(newint_point(84)));
        printf("terceiro print\n");
        print_stack(stack);
		return (0);
}
*/