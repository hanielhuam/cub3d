/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:35:39 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/09 20:40:02 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	siz1;
	size_t	siz2;
	char	*result;

	if (!(s1 && s2))
		return (NULL);
	siz1 = ft_strlen(s1);
	siz2 = ft_strlen(s2);
	result = ft_calloc(siz1 + siz2 + 1, sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcat(result, s1, siz1 + 1);
	ft_strlcat(result, s2, siz1 + siz2 + 1);
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	//concatenate 2 words
	printf("%s\n", ft_strjoin("Haniel", "Huam"));
	//concatenate 2 words, even if its a empty word
	printf("%s\n", ft_strjoin("Haniel", ""));
	//concatenate 2 words, even if its a empty word
	printf("%s\n", ft_strjoin("", "Haniel"));
	return (0);
}*/
