/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:40:48 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/03/20 20:14:46 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_comand	*create_comand(char c)
{
	t_comand	*comand;

	comand = (t_comand *)malloc(sizeof(t_comand) * 1);
	if (!comand)
		return (NULL);
	comand->type = c;
	return (comand);
}

static t_comand	*which_comand(char c)
{
	if (ft_strchr("cspdiuxX%", c))
		return (create_comand(c));
	else
		return (NULL);
}

t_print	*create_print(char *str)
{
	t_print	*print;

	print = (t_print *)malloc(sizeof(t_print) * 1);
	if (!print)
		return (NULL);
	print->original = ft_strdup(str);
	if (!print->original)
		return (NULL);
	print->comand = which_comand(*str);
	if (!print->comand)
		return (NULL);
	return (print);
}

t_list	*to_t_list(char **matrix, int first)
{
	t_list	*list;
	t_print	*print;

	list = NULL;
	if (!first)
	{
		print = (t_print *)malloc(sizeof(t_print));
		if (!print)
			return (NULL);
		print->original = ft_strdup(*matrix++);
		print->comand = NULL;
		ft_lstadd_back(&list, ft_lstnew(print));
	}
	while (*matrix)
	{
		print = create_print(*matrix++);
		if (!print)
		{
			ft_lstclear(&list, del_print);
			return (NULL);
		}
		ft_lstadd_back(&list, ft_lstnew(print));
	}
	return (list);
}

void	del_print(void *p)
{
	t_print	*print;

	if (!p)
		return ;
	print = p;
	free(print->original);
	free(print->replaciment);
	free(print->comand);
	free(p);
}
