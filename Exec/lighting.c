/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:45:52 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/10 19:39:03 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

t_material	material(void)
{
	t_material	m;

	m.color = (t_color){6, 8, 5};
	m.diffuse = 1;
	m.specular = 1;
	m.shininess = 200;
	return (m);
}

t_light	point_light(t_vector position, t_color colors)
{
	t_light	light;

	light.position = position;
	light.colors = colors;
	return (light);
}

t_color	shade_hit(t_world *world, t_comps comps)
{
	return (lighting(world, comps, is_shadowed(world, comps.over_point)));
}

// static float	calculate_shininess(t_comps comps, t_world *world)
// {
// 	float		shininess;

// 	shininess = distance_points(comps.t, world->light.position);
// 	return (shininess);
// }

t_color	lighting(t_world *world, t_comps comps, bool in_shadow)
{
	t_color		effective_color;
	t_color		ambient;
	t_color		diffuse;
	t_color		specular;
	t_vector	lightv;
	t_vector	reflectv;
	t_material	m = comps.object->material;
	float		light_dot_normal;
	float		reflect_dot_eye;
	float		factor;

	effective_color = m.color * world->light.brightness;
	lightv = normalize(world->light.position - comps.point);
	ambient = effective_color * world->ambient.brightness;
	light_dot_normal = dot_product(lightv, comps.normalv);
	if (light_dot_normal < 0 || in_shadow)
	{
		diffuse = (t_color){0, 0, 0};
		specular = (t_color){0, 0, 0};
	}
	else
	{
		diffuse = effective_color * light_dot_normal;
		reflectv = reflect(-lightv, comps.normalv);
		reflect_dot_eye = dot_product(reflectv, comps.eyev);
		if (reflect_dot_eye <= 0)
			specular = (t_color){0, 0, 0};
		else
		{
			// m.shininess = calculate_shininess(comps, world);
			factor = powf(reflect_dot_eye, m.shininess);
			specular = world->light.colors * factor;
		}
	}
	return ((ambient + diffuse + specular));
}

t_color	color_at(t_world *world, t_ray r)
{
	t_comps	comps;

	intersect(world, r);
	if (!hit(world))
		return ((t_color){0, 0, 0});
	else
	{
		comps = prepare_computations(hit(world), r);
		return (shade_hit(world, comps));
	}
}
