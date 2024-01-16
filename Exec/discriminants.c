/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discriminants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:14:49 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/16 20:52:53 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

t_discriminant	sphere_discriminant(t_ray	r, t_sphere	sp)
{
	t_vector			sphere_to_ray;
	t_discriminant		d;

	sphere_to_ray = sub_vecs(r.origin, sp.origin);
	d.a = dot_product(r.direction, r.direction);
	d.b = 2 * dot_product(r.direction, sphere_to_ray);
	d.c = dot_product(sphere_to_ray, sphere_to_ray) - (sp.rayon * sp.rayon);
	d.disc = powf(d.b, 2) - (4 * d.a * d.c);
	d.t1 = (-d.b - sqrtf(d.disc)) / (2 * d.a);
	d.t2 = (-d.b + sqrtf(d.disc)) / (2 * d.a);
	return (d);
}

t_discriminant	cylinder_discriminant(t_ray	r, t_cylinder	cy)
{
	t_discriminant		d;

	(void)cy;
	d.a = powf(r.direction.x, 2.0f) + powf(r.direction.z, 2.0f);
	d.b = 2 * r.origin.x * r.direction.x + \
		2 * r.origin.z * r.direction.z;
	d.c = powf(r.origin.x, 2.0f) + powf(r.origin.z, 2.0f) - 1;
	d.disc = powf(d.b, 2) - (4 * d.a * d.c);
	d.t1 = (-d.b - sqrtf(d.disc)) / (2 * d.a);
	d.t2 = (-d.b + sqrtf(d.disc)) / (2 * d.a);
	return (d);
}

t_discriminant	cone_discriminant(t_ray	r, t_cone co)
{
	t_discriminant		d;

	(void)co;
	d.a = (pow(r.direction.x, 2) - pow(r.direction.y, 2)
			+ pow(r.direction.z, 2));
	d.b = (2.0 * r.origin.x * r.direction.x)
		- (2.0 * r.origin.y * r.direction.y)
		+ (2.0 * r.origin.z * r.direction.z);
	d.c = pow(r.origin.x, 2) - pow(r.origin.y, 2)
		+ pow(r.origin.z, 2);
	d.disc = powf(d.b, 2) - (4 * d.a * d.c);
	d.t1 = (-d.b - sqrtf(d.disc)) / (2 * d.a);
	d.t2 = (-d.b + sqrtf(d.disc)) / (2 * d.a);
	return (d);
}
