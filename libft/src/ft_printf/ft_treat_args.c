/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 21:02:01 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/03/20 21:05:55 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*treat_args()
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
