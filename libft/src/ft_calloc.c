/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:09:40 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/27 13:15:27 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!nmemb || !size)
		return (malloc(0));
	if ((nmemb * size) % size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*
#include <stdio.h>

void	show_long(long *ptr, size_t nmemb);
void	show_int(int *ptr, size_t nmemb);
void	show_emptystring(char *ptr, size_t nmemb);

int	main(void)
{
	char	*ptrchar;
	int	*ptrint;
	long	*ptrlong;
	size_t	nmemb;

	nmemb = 4;
	ptrchar = (char *) ft_calloc(0, 0);
	ptrchar = (char *) ft_calloc(nmemb, sizeof(char));
	ptrint = (int *) ft_calloc(nmemb, sizeof(int));
	ptrlong = (long *) ft_calloc(nmemb, sizeof(long));
	show_emptystring(ptrchar, nmemb);
	show_int(ptrint, nmemb);
	show_long(ptrlong, nmemb);
}

void	show_long(long *ptr, size_t nmemb)
{
	while (nmemb--)
		printf("%ld\n", ptr[nmemb]);
	printf("\n");
}

void	show_int(int *ptr, size_t nmemb)
{
	while (nmemb--)
		printf("%d", ptr[nmemb]);
	printf("\n");	
}

void	show_emptystring(char *ptr, size_t nmemb)
{
	while (nmemb--)
	{
		if (ptr[nmemb] == '\0')
			printf("%s", "\\0");
	}
	printf("\n");
}*/
