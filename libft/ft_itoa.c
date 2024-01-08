/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:23:38 by mbekouch          #+#    #+#             */
/*   Updated: 2023/04/02 12:11:59 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int c)
{
	int	i;

	i = 0;
	while (c != 0)
	{
		c /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			i;
	int			size;
	char		*str;
	long int	c;

	i = 0;
	c = n;
	size = ft_size(c);
	if (c <= 0)
		size++;
	str = (char *)ft_calloc(size + 1, sizeof(char));
	if (c < 0)
	{
		c *= -1;
		str[0] = '-';
		i++;
	}
	while (size-- > i)
	{
		str[size] = (c % 10) + '0';
		c /= 10;
	}
	return (str);
}
