/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:56:58 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/08 20:42:28 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

bool	is_shadowed(t_world *world, t_point point)
{
	t_vector	v;
	t_ray		r;
	t_intersect	*h;

	v = world->light.position - point;
	r = create_ray(point, normalize(v));
	intersect(world, r);
	h = hit(world);
	if (h && (h->t < magnitude(v)))
		return (true);
	else
		return (false);
}
