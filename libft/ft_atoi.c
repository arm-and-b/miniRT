/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:57:12 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/06 22:21:24 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_it(const char *str, t_world *world)
{
	int	i;

	i = -1;
	while (str[++i] && str[i] != '\n')
		if (!ft_isdigit(str[i]))
			ft_error("Forbidden Character", true, world);
}

int	ft_atoi(const char *nptr, t_world *world, int *i)
{
	int		sign;
	long	value;

	*i = 0;
	sign = 1;
	value = 0;
	while ((nptr[*i] >= 9 && nptr[*i] <= 13) || nptr[*i] == ' ')
		*i += 1;
	check_it(nptr + *i, world);
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			sign = -sign;
		*i += 1;
	}
	while (nptr[*i] && nptr[*i] >= '0' && nptr[*i] <= '9')
	{
		value = value * 10 + nptr[*i] - '0';
		*i += 1;
	}
	if (value > INT_MAX)
		ft_error("Overflow", true, world);
	return (value * sign);
}
