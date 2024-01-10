/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:13:17 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/10 20:03:29 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

void	intersect(t_world	*world, t_ray	r)
{
	t_element	*tmp;

	tmp = *world->objects;
	while (tmp)
	{
		if (tmp->type == 1)
			intersect_sphere(tmp, world, r);
		else if (tmp->type == 2)
			intersect_plane(tmp, world, r);
		// else if (tmp->type == CYLINDER)
		// 	intersect_cylinder((t_cylinder *)tmp, world);
		tmp = tmp->next;
	}
}

void	intersect_sphere(t_element	*sphere, t_world	*world, t_ray r)
{
	t_discriminant	d;

	d = sphere_discriminant(r, sphere->sphere);
	if (d.disc < 0)
		return ;
	intersection(d.t1, sphere, world);
	intersection(d.t2, sphere, world);
}

void	intersect_plane(t_element *plane, t_world *world, t_ray r)
{
	float	t;

	if (fabsf(r.direction.y) < EPSILON)
		return ;
	t = (-r.origin.y) / r.direction.y;
	intersection(t, plane, world);
}

void	intersection(float t, t_element *element, t_world *world)
{
	static t_intersect	list[256];
	static size_t	i;
	t_intersect	*interse;
	t_intersect	*precedent;
	t_intersect	*actuel;
	t_intersect	**xs;

	interse = list + (i++ % 256);
	interse->t = t;
	interse->element = element;
	interse->next = NULL;
	precedent = NULL;
	xs = &world->intersections;
	actuel = *xs;
	while (actuel && actuel->t < interse->t)
	{
		precedent = actuel;
		actuel = actuel->next;
	}
	if (precedent == NULL)
	{
		interse->next = *xs;
		*xs = interse;
		return ;
	}
	precedent->next = interse;
	interse->next = actuel;
}

t_comps	prepare_computations(t_intersect *i, t_ray r)
{
	t_comps	c;

	c.t = i->t;
	c.object = i->element;
	c.point = position(r, c.t);
	c.eyev = -r.direction;
	c.normalv = normal_at(c.object, c.point);
	c.inside = false;
	if (dot_product(c.normalv, c.eyev) < 0)
	{
		c.inside = true;
		c.normalv = -c.normalv;
	}
	c.over_point = c.point + c.normalv * EPSILON;
	return (c);
}
