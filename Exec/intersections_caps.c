/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections_caps.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinet <abinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:54:40 by abinet            #+#    #+#             */
/*   Updated: 2024/01/16 16:46:16 by abinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

bool	check_cap(t_ray r, float t)
{
	float	x;
	float	z;

	x = r.origin.x + t * r.direction.x;
	z = r.origin.z + t * r.direction.z;
	return (x * x + z * z <= 1);
}

void	intersect_caps(t_element *cy, t_ray ray, t_world *world)
{
	float	t;

	if (!cy->cylinder.closed || fabsf(ray.direction.y) < EPSILON)
		return ;
	t = (cy->cylinder.minimum - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t))
		intersection(t, cy, world);
	t = (cy->cylinder.maximum - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t))
		intersection(t, cy, world);
}

bool	check_cap_cone(t_ray ray, float t, float cone_range)
{
	double	x;
	double	z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	return ((pow(x, 2) + pow(z, 2)) <= pow(cone_range, 2));
}

void	intersect_caps_cone(t_element *co, t_ray ray, t_world *world)
{
	float	t;

	if (!co->cone.closed || fabsf(ray.direction.y) < EPSILON)
		return ;
	t = (co->cone.minimum - ray.origin.y) / ray.direction.y;
	if (check_cap_cone(ray, t, co->cone.minimum))
		intersection(t, co, world);
	t = (co->cone.maximum - ray.origin.y) / ray.direction.y;
	if (check_cap_cone(ray, t, co->cone.maximum))
		intersection(t, co, world);
}
