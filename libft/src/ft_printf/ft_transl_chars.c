/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transl_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:05:09 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/12/16 15:57:40 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*translate_c(t_print *print, int c)
{
	char	*dup;

	dup = ft_strdup(print->original);
	print->size = ft_strlen(dup);
	dup[0] = c;
	return (dup);
}

static char	*translate_s(t_print *print, char *s)
{
	char	*temp;
	char	*sub;
	char	*result;

	if (!s)
		temp = ft_strdup("(null)");
	else
		temp = ft_strdup(s);
	sub = ft_substr(print->original, 1, ft_strlen(print->original) - 1);
	result = ft_strjoin(temp, sub);
	print->size = ft_strlen(result);
	free(temp);
	free(sub);
	return (result);
}

char	*translate_characters(t_print *print, va_list args, char type)
{
	if (type == 'c')
		return (translate_c(print, va_arg(args, int)));
	if (type == '%')
		return (translate_c(print, '%'));
	if (type == 's')
		return (translate_s(print, va_arg(args, char *)));
	else
	{
		print->size = ft_strlen(print->original);
		return (ft_strdup(print->original));
	}
}
