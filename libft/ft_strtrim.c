/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:21:54 by mbekouch          #+#    #+#             */
/*   Updated: 2023/10/30 18:53:16 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set(const char *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	min;
	size_t	max;
	size_t	i;

	min = 0;
	if (!s1 || !set)
		return (NULL);
	max = ft_strlen(s1);
	while (s1[min] && ft_set(set, s1[min]))
		min++;
	while (max > min && ft_set(set, s1[max - 1]))
		max--;
	str = (char *)ft_calloc(sizeof(char), (max - min + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (min < max)
		str[i++] = s1[min++];
	return (str);
}
