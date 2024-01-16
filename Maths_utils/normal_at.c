/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinet <abinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:36:26 by abinet            #+#    #+#             */
/*   Updated: 2024/01/16 16:47:05 by abinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

static t_vector	find_local_normal_cylinder(t_element *elem, t_vector p)
{
	t_point		lp;
	t_vector	local_normal;
	float		dist;

	lp = vect_x_matrix(elem->inverse, p);
	lp.w = 1.0;
	dist = powf(lp.x, 2.0) + powf(lp.z, 2.0);
	if (dist < 1.0 && lp.y >= elem->cylinder.maximum - EPSILON)
		local_normal = vector(0, 1, 0);
	else if (dist < 1.0 && lp.y <= elem->cylinder.minimum + EPSILON)
		local_normal = vector(0, -1, 0);
	else
		local_normal = vector(lp.x, 0, lp.z);
	return (normalize(local_normal));
}

static t_vector	find_local_normal_cone(t_element *elem, t_vector p)
{
	t_point		lp;
	t_vector	local_normal;
	float		dist;

	lp = vect_x_matrix(elem->inverse, p);
	lp.w = 1.0;
	dist = powf(lp.x, 2.0) + powf(lp.z, 2.0);
	if (dist < powf((1.0 + elem->cone.rayon / elem->cone.height), 2.0) && \
			lp.y >= elem->cone.maximum - EPSILON)
		local_normal = vector(0, 1, 0);
	else if (dist < powf((1.0 + elem->cone.rayon / elem->cone.height), 2.0) && \
			lp.y <= elem->cone.minimum + EPSILON)
		local_normal = vector(0, -1, 0);
	else
		local_normal = vector(lp.x, -elem->cone.rayon, lp.z);
	return (normalize(local_normal));
}

t_vector	normal_at(t_element *elem, t_vector p)
{
	t_point		lp;
	t_vector	local_normal;
	t_vector	world_normal;

	lp = vect_x_matrix(elem->inverse, p);
	lp.w = 1.0;
	if (elem->type == SPHERE)
		local_normal = lp - point(0, 0, 0);
	if (elem->type == PLANE)
		local_normal = vector(0, 1, 0);
	if (elem->type == CYLINDER)
		local_normal = find_local_normal_cylinder(elem, p);
	if (elem->type == CONE)
		local_normal = find_local_normal_cone(elem, p);
	world_normal = vect_x_matrix(transpose(elem->inverse), \
			local_normal);
	world_normal.w = 0.0;
	return (normalize(world_normal));
}
