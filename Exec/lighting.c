/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinet <abinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:45:52 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/14 00:12:55 by abinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

t_material	material(void)
{
	t_material	m;

	m.color = (t_color){6, 8, 5};
	m.shininess = 20.0f;
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

	m = comps.object->material;
	lc.effective_color = m.color * world->light.colors;
	lc.lightv = normalize(world->light.position - comps.over_point);
	lc.ambient = lc.effective_color * world->ambient.colors * world->ambient.brightness;
	lc.light_dot_normal = dot_product(lc.lightv, comps.normalv);
	if (lc.light_dot_normal < 0 || in_shadow)
		return (lc.ambient);
	lc.diffuse = lc.effective_color * lc.light_dot_normal;
	lc.reflectv = reflect(negate(lc.lightv), comps.normalv);
	lc.reflect_dot_eye = dot_product(lc.reflectv, comps.eyev);
	if (lc.reflect_dot_eye <= 0)
		return (lc.ambient + lc.diffuse);
	lc.factor = powf(lc.reflect_dot_eye, m.shininess);
	lc.specular = world->light.colors * lc.factor;
	return ((lc.ambient + lc.diffuse + lc.specular));
}

t_color	color_at(t_world *world, t_ray r)
{
	intersect(world, r);
	if (!hit(world))
		return ((t_color){0, 0, 0});
	return (shade_hit(world, prepare_computations(hit(world), r)));
}
