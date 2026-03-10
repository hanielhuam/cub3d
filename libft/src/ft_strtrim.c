/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:42:06 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/10/27 18:21:21 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!*s1 || !set || !*set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[start] && ft_strchr(set, s1[end]))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
/*
#include <stdio.h>

int	main(void)
{
	//test when s is '\0'
	printf("%s\n", ft_strtrim("", "123"));
	//test when there is characters to trim at the start and the end of s
	printf("%s\n", ft_strtrim("-Haniel-", "-"));
	//test when there is characters to trim only at thetart
	printf("%s\n", ft_strtrim("-Haniel", "-"));
	//test when there is characters to trim only at the end
	printf("%s\n", ft_strtrim("Haniel-", "-"));
	//test when there is NO characters to trim
	printf("%s\n", ft_strtrim("Haniel", "-"));
	//test when there is characters on the set but in the midle of s
	printf("%s\n", ft_strtrim("Haniel-Huam-Macedo-Ferreura", "-"));
	//test when there is multiple characters to trim
	printf("%s\n", ft_strtrim("--Haniel--", "-"));
	//test when there is multiple characters to trim with more set character
	printf("%s\n", ft_strtrim("-+Haniel+-", "-+"));
	//test when set is null
	printf("%s\n", ft_strtrim("--Haniel--", NULL));
	//test when s is null
	printf("%s\n", ft_strtrim(NULL, "-"));
	//test when there is characters to trim at the start and the end of s
	printf("%s\n", ft_strtrim("-Haniel-", "-"));
	return (0);
}*/
