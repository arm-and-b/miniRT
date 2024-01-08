/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:18:07 by mbekouch          #+#    #+#             */
/*   Updated: 2023/04/02 13:36:30 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*((const char *)s) == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*((unsigned char *)s1) != *((unsigned char *)s2))
			return (*((unsigned char *)s1) - *((unsigned char *)s2));
		s1++;
		s2++;
	}
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*tmp;

	tmp = dst;
	while (n-- && src)
	{
		*tmp = *((const char *)src);
		tmp++;
		src++;
	}
	return (dst);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		d = (char *)dest + n -1;
		s = (char *)src + n -1;
		while (n--)
			*d-- = *s--;
	}
	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	while (n--)
	{
		*tmp = (unsigned char)c;
		tmp++;
	}
	return (s);
}
