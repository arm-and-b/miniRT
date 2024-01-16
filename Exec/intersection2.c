/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:32:50 by abinet            #+#    #+#             */
/*   Updated: 2024/01/16 20:51:15 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

t_comps	prepare_computations(t_intersect *i, t_ray r)
{
	t_comps	c;

	c.t = i->t;
	c.object = i->element;
	c.point = position(r, c.t);
	c.eyev = negate(r.direction);
	c.normalv = normal_at(c.object, c.point);
	c.inside = false;
	if (dot_product(c.normalv, c.eyev) < 0)
	{
		c.inside = true;
		c.normalv = negate(c.normalv);
	}
	c.over_point = c.point + c.normalv * EPSILON * 100;
	return (c);
}

void	intersect_cone(t_element *cone, t_world *world, t_ray r)
{
	t_discriminant	d;
	float			y1;
	float			y2;

	r = transform(r, cone->inverse);
	d = cone_discriminant(r, cone->cone);
	intersect_caps_cone(cone, r, world);
	if (d.disc < 0 || fabsf(d.a) < EPSILON)
		return ;
	if (d.t1 > d.t2)
		swap_float(&d.t1, &d.t2);
	y1 = r.origin.y + d.t1 * r.direction.y;
	if (cone->cone.minimum < y1 && y1 < cone->cone.maximum)
		intersection(d.t1, cone, world);
	y2 = r.origin.y + d.t2 * r.direction.y;
	if (cone->cone.minimum < y2 && y2 < cone->cone.maximum)
		intersection(d.t2, cone, world);
}
