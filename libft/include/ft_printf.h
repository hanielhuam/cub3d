/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:24:26 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/03/24 18:44:19 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "ft_list.h"

# define COMANDS "cspdiuxX%"
# define BASE_10 "0123456789"
# define BASE_16 "0123456789abcdef"
# define BASE_16U "0123456789ABCDEF"

typedef struct s_print
{
	char			*original;
	char			*replaciment;
	int				size;
	struct s_comand	*comand;
}					t_print;

typedef struct s_comand
{
	char	flag;
	int		lenght;
	char	prcision;
	int		nu_precision;
	char	type;
}			t_comand;

int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
t_list  *to_t_list(char **matrix, int first);
t_print	*create_print(char *str);
t_list	*treat_args(const char *format);
int		translate(t_list *list, va_list args);
char	*translate_characters(t_print *print, va_list args, char type);
char	*translate_digits(t_print *print, va_list args);
char	*translate_udigits(t_print *print, va_list args, char type);
char	*translate_no(t_print *print);
void	del_print(void *p);

#endif
