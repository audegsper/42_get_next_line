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

#include "get_next_line.h"

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

char* ft_strjoin(char const* s1, char const* s2)
{
	char* x;
	size_t	c1;
	size_t	c2;
	size_t	i;
	size_t	ls1 = ft_strlen(s1);	// kyuhkim
	size_t	ls2 = ft_strlen(s2);	// kyuhkim

	i = 0;
	c2 = 0;
	c1 = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (!s1 || !s2)
		return (!s1 ? ft_strdup(s2) : ft_strdup(s1));
	if (!(x = (char*)malloc(sizeof(char) * (ls1 + ls2 + 1))))
		return (NULL);
	while (c1 != ls1)
	{
		x[i] = s1[c1];
		++i&& ++c1;
	}
	while (c2 != ls2)
	{
		x[i] = s2[c2];
		++i&& ++c2;
	}
	x[i] = '\0';
	free((char*)s1);
	return (x);
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
