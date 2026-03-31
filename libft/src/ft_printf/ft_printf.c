/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:49:10 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/03/30 20:12:39 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	show(t_list *list, int fd)
{
	t_print	*print;
	int		count;

	count = 0;
	while (list)
	{
		print = list->content;
		count += write(fd, print->replaciment, print->size);
		list = list->next;
	}
	return (count);
}

static int	translation(t_list *list, va_list args, int fd)
{
	int		count;
	int		error;

	error = translate(list, args);
	va_end(args);
	count = -1;
	if (!error)
		count = show(list, fd);
	ft_lstclear(&list, del_print);
	return (count);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	t_list	*list_print;
	va_list	args;

	list_print = treat_args(format);
	if (!list_print)
		return (-1);
	va_start(args, format);
	return (translation(list_print, args, fd));
}

int	ft_printf(const char *format, ...)
{
	t_list	*list_print;
	va_list	args;

	list_print = treat_args(format);
	if (!list_print)
		return (-1);
	va_start(args, format);
	return (translation(list_print, args, STDOUT_FILENO));
}
/*
#include <stdio.h>

int main ()
{
	int res = ft_printf("um teste");
	ft_printf("\n%d", res);
}*/
