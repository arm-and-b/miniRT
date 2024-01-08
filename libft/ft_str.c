/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:28:08 by mbekouch          #+#    #+#             */
/*   Updated: 2023/11/05 18:41:37 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	size_t	i;

	ptr = 0;
	i = 0;
	while (s && s[i])
	{
		if (s[i] == (char)c)
		{
			ptr = (char *)&s[i];
			break ;
		}
		i++;
	}
	if (s[i] == (char)c)
			ptr = (char *)&s[i];
	return (ptr);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	size_t	i;

	ptr = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			ptr = (char *)&s[i];
		i++;
	}
	if (s[i] == (char)c)
			ptr = (char *)&s[i];
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen((char *)src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen((char *)src));
}

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	src_size;
	size_t	dest_size;
	size_t	i;

	i = 0;
	src_size = ft_strlen(src);
	dest_size = ft_strlen(dest);
	if (size == 0)
		return (src_size);
	while (src[i] && dest_size + i + 1 < size)
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	if (dest_size > size)
		return (src_size + size);
	else
		dest[dest_size + i] = '\0';
	return (src_size + dest_size);
}
