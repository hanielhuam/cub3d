/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 20:39:39 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/03/30 20:39:38 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static char	*get_together(t_list *list)
{
	char	*result;

	result = ft_calloc(1, sizeof(char));
	while (list)
	{
		result = ft_join_free(result, ((t_print *)list->content)->replaciment);
		if (!result)
			return (NULL);
		list = list->next;
	}
	return (result);
}

char	*ft_strformat(const char *format, ...)
{
	t_list	*list;
	va_list	args;
	char	*result;

	list = treat_args(format);
	if (!list)
		return (NULL);
	va_start(args, format);
	result = NULL;
	if (!translate(list, args))
		result = get_together(list);
	va_end(args);
	ft_lstclear(&list, del_print);
	return (result);
}
