/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:45:52 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/13 06:27:22 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

t_material	material(void)
{
	t_material	m;

	m.color = (t_color){6, 8, 5};
	m.shininess = 2000.0f;
	return (m);
}

t_color	shade_hit(t_world *world, t_comps comps)
{
	return (lighting(world, comps, is_shadowed(world, comps.over_point)));
}

t_color	lighting(t_world *world, t_comps comps, bool in_shadow)
{
	t_lighting	lc;
	t_material	m;
	float		intensity;

	m = comps.object->material;
	intensity = ((world->ambient.brightness * 0.5f \
	+ world->light.brightness) / 2.0f);
	lc.effective_color = m.color * world->light.colors * intensity;
	lc.lightv = normalize(world->light.position - comps.over_point);
	lc.ambient = lc.effective_color * world->ambient.colors;
	lc.light_dot_normal = dot_product(lc.lightv, comps.normalv);
	if (lc.light_dot_normal < 0 || in_shadow)
		return (lc.ambient);
	lc.diffuse = lc.effective_color * lc.light_dot_normal;
	lc.reflectv = reflect(negate(lc.lightv), comps.normalv);
	lc.reflect_dot_eye = dot_product(lc.reflectv, comps.eyev);
	if (lc.reflect_dot_eye <= 0)
		return (lc.ambient + lc.diffuse);
	lc.factor = powf(lc.reflect_dot_eye, m.shininess);
	lc.specular = world->light.colors * lc.factor / intensity;
	return (lc.ambient + (lc.diffuse + lc.specular));
}

t_color	color_at(t_world *world, t_ray r)
{
	intersect(world, r);
	if (!hit(world))
		return ((t_color){0, 0, 0});
	return (shade_hit(world, prepare_computations(hit(world), r)));
}
