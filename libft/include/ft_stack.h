/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:44:46 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/04/21 18:30:41 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include "libft.h"

typedef struct s_stack
{
	void			*content;
	int				index;
	struct s_stack	*next;
	struct s_stack	*before;
}					t_stack;

void	ft_stckswap(t_stack **stack);
void	ft_stckpush(t_stack **stack_from, t_stack **stack_to);
void	ft_stckrotate(t_stack **stack, int reverse);
t_stack	*ft_stcknew(void *content);
void	ft_stckadd_front(t_stack **stack, t_stack *new);
int		ft_stckcheck(t_stack **stack);
int		ft_stcksize(t_stack **stack);	
void	ft_stckadd_back(t_stack **stack, t_stack *new);
void	ft_stckdelone(t_stack *element, void (*del)(void *));
void	ft_stckclear(t_stack **stack, void (*del)(void *));
void	ft_stckiter(t_stack *stack, void (*f)(void *));
t_stack	*ft_stckmap(t_stack *stack, void *(*f)(void *), void (*del)(void *));
void	ft_stckiter_s(t_stack *stack, void (*f)(t_stack *));

#endif 
