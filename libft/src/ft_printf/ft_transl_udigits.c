/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transl_udigits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:47:42 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/12/16 15:50:28 by hmacedo-         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*transl_ud(t_print *print, unsigned int n, char *base)
{
	char	*number;
	char	*sub;
	char	*result;

	number = ft_ulitoa_base((unsigned long int) n, base);
	sub = ft_substr(print->original, 1, ft_strlen(print->original) - 1);
	result = ft_strjoin(number, sub);
	print->size = ft_strlen(result);
	free(number);
	free(sub);
	return (result);
}

static char	*transl_p(t_print *print, void *p, char *base)
{
	char	*temp;
	char	*num;
	char	*sub;
	char	*result;

	if (!p)
		temp = ft_strdup("(nil)");
	else
	{
		temp = ft_strdup("0x");
		num = ft_ulitoa_base((unsigned long int)p, base);
		result = ft_strjoin(temp, num);
		free(temp);
		free(num);
		temp = result;
	}
	sub = ft_substr(print->original, 1, ft_strlen(print->original) - 1);
	result = ft_strjoin(temp, sub);
	print->size = ft_strlen(result);
	free(temp);
	free(sub);
	return (result);
}

char	*translate_udigits(t_print *print, va_list args, char type)
{
	if (type == 'u')
		return (transl_ud(print, va_arg(args, unsigned int), BASE_10));
	if (type == 'x')
		return (transl_ud(print, va_arg(args, unsigned int), BASE_16));
	if (type == 'X')
		return (transl_ud(print, va_arg(args, unsigned int), BASE_16U));
	if (type == 'p')
		return (transl_p(print, va_arg(args, void *), BASE_16));
	else
	{
		print->size = ft_strlen(print->original);
		return (ft_strdup(print->original));
	}
}
