/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinet <abinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:13:17 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/15 18:33:21 by abinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

void	intersection(float t, t_element *element, t_world *world)
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

void	intersect_cylinder(t_element *cylinder, t_world *world, t_ray r)
{
	t_discriminant	d;

	r = transform(r, cylinder->inverse);
	d = cylinder_discriminant(r, cylinder->cylinder);
	intersect_caps(cylinder, r, world);
	if (d.disc < 0 || d.a < EPSILON)
		return ;
	if (d.t1 > d.t2)
		swap_float(&d.t1, &d.t2);
	float	y1 = r.origin.y + d.t1 * r.direction.y;
	if (cylinder->cylinder.minimum < y1 && y1 < cylinder->cylinder.maximum)
		intersection(d.t1, cylinder, world);
	float	y2 = r.origin.y + d.t2 * r.direction.y;
	if (cylinder->cylinder.minimum < y2 && y2 < cylinder->cylinder.maximum)
		intersection(d.t2, cylinder, world);
}

void	intersect(t_world	*world, t_ray	r)
{
	t_element	*tmp;

	tmp = *world->objects;
	world->intersections = NULL;
	while (tmp)
	{
		if (tmp->type == 1)
			intersect_sphere(tmp, world, r);
		else if (tmp->type == 2)
			intersect_plane(tmp, world, r);
		else if (tmp->type == 3)
			intersect_cylinder(tmp, world, r);
		tmp = tmp->next;
	}
}
