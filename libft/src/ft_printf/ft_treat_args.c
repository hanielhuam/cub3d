/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 21:02:01 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/03/23 21:17:48 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*treat_args(char *format)
{
	char	first;
	char	**matrix;
	char	**temp;
	t_list	*list_print;

	if (!format)
		return (-1);
	first = 0;
	if (format == '%')
		first = 1;
	matrix = ft_separate(format, '%');
	if (!matrix)
		return (NULL);
	list_print = to_t_list(matrix, first);
	temp = matrix;
	while (*matrix)
		free(*matrix++);
	free(temp);
	return (list_print);
}
