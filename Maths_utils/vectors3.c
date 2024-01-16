/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinet <abinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:59:41 by abinet            #+#    #+#             */
/*   Updated: 2024/01/16 12:36:42 by abinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

float	magnitude(t_vector v)
{
	return (sqrtf(powf(v.x, 2.0) + powf(v.y, 2.0) + powf(v.z, 2.0)));
}

t_vector	normalize(t_vector v)
{
	t_vector	c;
	float		d;

	d = magnitude(v);
	if (d == 0.00000)
		return (v);
	c.x = v.x / d;
	c.y = v.y / d;
	c.z = v.z / d;
	c.w = v.w / d;
	return (c);
}

t_vector	reflect(t_vector in, t_vector normal)
{
	return (in - normal * 2.0 * dot_product(in, normal));
}

t_vector	negate(t_vector v)
{
	return (vector(-v.x, -v.y, -v.z));
}
