/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinet <abinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:13:17 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/13 23:44:14 by abinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

static void	intersection(float t, t_element *element, t_world *world)
{
	static t_intersect	list[256];
	static size_t		i;
	t_intersect			*inter[3];
	t_intersect			**xs;

	inter[0] = list + (i++ % 256);
	inter[0]->t = t;
	inter[0]->element = element;
	inter[0]->next = NULL;
	inter[1] = NULL;
	xs = &world->intersections;
	inter[2] = *xs;
	while (inter[2] && inter[2]->t < inter[0]->t)
	{
		inter[1] = inter[2];
		inter[2] = inter[2]->next;
	}
	if (inter[1] == NULL)
	{
		inter[0]->next = *xs;
		*xs = inter[0];
		return ;
	}
	inter[1]->next = inter[0];
	inter[0]->next = inter[2];
}

static void	intersect_sphere(t_element	*sphere, t_world	*world, t_ray r)
{
	t_discriminant	d;

	d = sphere_discriminant(r, sphere->sphere);
	if (d.disc < 0)
		return ;
	intersection(d.t1, sphere, world);
	intersection(d.t2, sphere, world);
}

static void	intersect_plane(t_element *plane, t_world *world, t_ray r)
{
	float	t;

	if (fabsf(r.direction.y) < EPSILON)
		return ;
	t = (-r.origin.y) / r.direction.y;
	intersection(t, plane, world);
}

// Pas encore fini
static void	intersect_cylinder(t_element *cylinder, t_world *world, t_ray r)
{
	t_discriminant	d;

	d = cylinder_discriminant(r, cylinder->cylinder);
	if (d.a < EPSILON)
		return ;
	if (d.disc < 0 || d.a < EPSILON)
		return ;
	intersection(d.t1, cylinder, world);
	intersection(d.t2, cylinder, world);
}


void	intersect(t_world	*world, t_ray	r)
{
	t_element	*tmp;
	t_ray		ray;

	tmp = *world->objects;
	world->intersections = NULL;
	while (tmp)
	{
		if (tmp->type == 1)
			intersect_sphere(tmp, world, r);
		else if (tmp->type == 2)
		{
			ray = transform(r, inverse(tmp->transform));
			intersect_plane(tmp, world, ray);
		}
		else if (tmp->type == 3)
			intersect_cylinder(tmp, world, r);
		tmp = tmp->next;
	}
}

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
