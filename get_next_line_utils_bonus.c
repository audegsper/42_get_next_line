/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:53:44 by dohykim           #+#    #+#             */
/*   Updated: 2021/02/24 21:21:08 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr_num(const char* s, int c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			return (i);
		++s;
		++i;
	}
	return (-1);
}

char* ft_strdup(const char* s)
{
	char* copy;
	size_t	i;

	if (!(copy = malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s1plus2;
	size_t	len_s1;
	size_t	len_s2;

	if (!(s1))
		return (ft_strdup(s2));
	if (!(s2))
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s1plus2 = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!(s1plus2))
		return (0);
	ft_memcpy(s1plus2, s1, len_s1);
	ft_memcpy(s1plus2 + len_s1, s2, len_s2);
	s1plus2[len_s1 + len_s2] = '\0';
	free((void *)s1);
	s1 = NULL;
	return (s1plus2);
}

void* ft_memcpy(void* dst, const void* src, size_t n)
{
	unsigned char* d;
	unsigned char* s;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (!dst && !src)
		return (dst);
	while (n--)
		*d++ = *s++;
	return (dst);
}

size_t	ft_strlen(const char* s)
{
	size_t i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}
