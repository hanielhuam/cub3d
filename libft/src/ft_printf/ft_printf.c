/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:49:10 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/12/17 13:30:43 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	translate(t_list *list, va_list args)
{
	t_print	*print;
	char	type;

	while (list)
	{
		print = list->content;
		if (print->comand)
		{
			type = print->comand->type;
			if (type == 'c' || type == '%' || type == 's')
				print->replaciment = translate_characters(print, args, type);
			if (type == 'd' || type == 'i')
				print->replaciment = translate_digits(print, args);
			if (type == 'u' || type == 'x' || type == 'X' || type == 'p')
				print->replaciment = translate_udigits(print, args, type);
		}
		else
			print->replaciment = translate_no(print);
		if (!print->replaciment)
			return (-1);
		list = list->next;
	}
	return (0);
}

int	show(t_list *list)
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

int	translation(char **matrix, t_list *list, va_list args)
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

int	ft_printf(const char *format, ...)
{
	char	first;
	char	**matrix;
	t_list	*list_print;
	va_list	args;

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
