/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:59:41 by abinet            #+#    #+#             */
/*   Updated: 2024/01/10 20:44:52 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

float	magnitude(t_vector v)
{
	return (sqrt(powf(v.x, 2) + powf(v.y, 2) + powf(v.z, 2)));
}

t_vector	normalize(t_vector v)
{
	t_vector	c;
	float		d;

	d = magnitude(v);
	if (d == 0)
		return (v);
	c.x = v.x / d;
	c.y = v.y / d;
	c.z = v.z / d;
	c.w = v.w / d;
	return (c);
}

t_vector	reflect(t_vector in, t_vector normal)
{
	t_vector	v;

	v = normal * 2.0 * dot_product(in, normal);
	return (sub_vecs(in, v));
}

t_vector	normal_at(t_element *elem, t_vector p)
{
	t_point		local_point;
	t_vector	local_normal = 0;
	t_vector	world_normal;

	local_point = vect_x_matrix(elem->inverse, p);
	local_point.w = 1.0;
	if (elem->type == 1)
		local_normal = local_point;
	else if (elem->type == 2)
		local_normal = vector(0, 1, 0);
	world_normal = vect_x_matrix(transpose(elem->inverse), \
			local_normal);
	world_normal.w = 0.0;
	return (normalize(world_normal));
}
