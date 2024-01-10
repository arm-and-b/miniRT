/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 01:17:54 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/10 19:55:31 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

t_ray	create_ray(t_vector origin, t_vector direction)
{
	return ((t_ray){origin, direction});
}

t_point	position(t_ray	r, float t)
{
	return (point(r.origin.x + (r.direction.x * t),
			r.origin.y + (r.direction.y * t),
			r.origin.z + (r.direction.z * t)
		));
}

t_ray	transform(t_ray	r, t_matrix m)
{
	t_ray	new;

	new.direction = vect_x_matrix(m, r.direction);
	new.direction.w = 0.0;
	new.origin = vect_x_matrix(m, r.origin);
	new.origin.w = 1.0;
	return (new);
}

// void	set_transform(t_element	*sphere, t_matrix m)
// {
// 	sphere->transform = m;
// }
