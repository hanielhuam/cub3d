/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transl_digits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:40:49 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/12/16 15:52:20 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*translate_d(t_print *print, int n)
{
	char	*number;
	char	*sub;
	char	*result;

	number = ft_litoa_base((long int) n, BASE_10);
	sub = ft_substr(print->original, 1, ft_strlen(print->original) - 1);
	result = ft_strjoin(number, sub);
	print->size = ft_strlen(result);
	free(number);
	free(sub);
	return (result);
}

char	*translate_digits(t_print *print, va_list args)
{
	return (translate_d(print, va_arg(args, int)));
}
