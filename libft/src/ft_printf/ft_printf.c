/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:49:10 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/03/20 21:30:15 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	show(t_list *list)
{
	t_print	*print;
	int		count;

	count = 0;
	while (list)
	{
		print = list->content;
		count += write(1, print->replaciment, print->size);
		list = list->next;
	}
	return (count);
}

static int	translation(char **matrix, t_list *list, va_list args)
{
	int		count;
	char	**matrix_temp;
	int		error;

	error = translate(list, args);
	va_end(args);
	count = -1;
	if (!error)
		count = show(list);
	ft_lstclear(&list, del_print);
	matrix_temp = matrix;
	while (*matrix)
		free(*matrix++);
	free(matrix_temp);
	return (count);
}

int ft_dprintf(int fd, const char *format, ...)
{
	
}

int	ft_printf(const char *format, ...)
{
	t_list	*list_print;
	va_list	args;

	list_print = 
	if (!format)
		return (-1);
	first = 0;
	if (*format != '%')
		first = 0;
	else
		first = 1;
	matrix = ft_separate(format, '%');
	if (!*matrix[0])
		return (-1);
	list_print = to_t_list(matrix, first);
	if (!list_print)
	{
		while (*matrix)
			free(*matrix++);
		free(matrix);
		return (-1);
	}
	va_start(args, format);
	return (translation(matrix, list_print, args));
}
/*
#include <stdio.h>

int main ()
{
	int res = ft_printf("um teste");
	ft_printf("\n%d", res);
}*/
