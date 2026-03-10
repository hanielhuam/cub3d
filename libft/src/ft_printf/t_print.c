/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:40:48 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/12/16 15:46:59 by hmacedo-         ###   ########.fr       */
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
