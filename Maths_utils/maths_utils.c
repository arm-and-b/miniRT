/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:45:58 by abinet            #+#    #+#             */
/*   Updated: 2023/12/10 00:08:20 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

bool	is_odd_nbr(unsigned int a)
{
	if (a % 2 == 0)
		return (false);
	else
		return (true);
}

float	radians(float deg)
{
	return (deg * (M_PI / 180.0));
}

bool	is_invertible(t_matrix	m)
{
	return (determinant(m) != 0);
}
