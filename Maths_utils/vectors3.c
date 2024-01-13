/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:59:41 by abinet            #+#    #+#             */
/*   Updated: 2024/01/13 05:16:11 by mbekouch         ###   ########.fr       */
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

t_vector	normal_at(t_element *elem, t_vector p)
{
	t_point		local_point;
	t_vector	local_normal;
	t_vector	world_normal;

	local_point = vect_x_matrix(elem->inverse, p);
	local_point.w = 1.0;
	if (elem->type == 1)
		local_normal = local_point - point(0, 0, 0);
	if (elem->type == 2)
		local_normal = vector(0, 1, 0);
	world_normal = vect_x_matrix(transpose(elem->inverse), \
			local_normal);
	world_normal.w = 0.0;
	return (normalize(world_normal));
}
