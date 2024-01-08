/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 06:07:03 by mbekouch          #+#    #+#             */
/*   Updated: 2023/12/15 20:55:26 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_atof(char *str, t_world *world)
{
	float	atof;
	int		atoi;
	int		i;
	int		fac;

	fac = 1;
	atof = 0;
	i = 0;
	atoi = ft_atoi(str, world, &i);
	if (i == (int)ft_strlen(str) || str[i] != '.')
		return (atoi);
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		fac *= 10;
		atof = atof * 10 + (str[i] - '0');
		i++;
	}
	atof /= fac;
	if (atoi < 0)
		return (atoi - atof);
	return (atoi + atof);
}
