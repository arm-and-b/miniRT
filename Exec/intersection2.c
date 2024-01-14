/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinet <abinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:32:50 by abinet            #+#    #+#             */
/*   Updated: 2024/01/14 22:11:53 by abinet           ###   ########.fr       */
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
	c.over_point = c.point + c.normalv * EPSILON;
	return (c);
}

bool	check_cap(t_ray r, float t, float radius)
{
	float	x;
	float	z;

	x = r.origin.x + t * r.direction.x;
	z = r.origin.z + t * r.direction.z;
	return (x * x + z * z <= radius);
}
