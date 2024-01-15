/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 12:45:02 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/15 21:04:51 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../MiniRT.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i + 1 < n && (s1[i] == s2[i] && (s1[i]) && (s2[i])))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	dest = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s1, ft_strlen(s1));
	ft_memcpy(dest + ft_strlen(s1), s2, ft_strlen(s2));
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*d;

	d = ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (d == NULL)
		return (NULL);
	ft_memcpy(d, s, (ft_strlen(s) +1));
	return (d);
}

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	i = 0;
	str = ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, \
size_t len, t_world *world)
{
	char	*sub;

	if (!s || start > ft_strlen(s))
		return (ft_malloc(sizeof(char), world));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = ft_malloc((len + 1) * sizeof(char), world);
	if (sub == NULL)
		return (NULL);
	ft_memcpy(sub, s + start, len);
	return (sub);
}
