/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:04:54 by mbekouch          #+#    #+#             */
/*   Updated: 2023/12/10 17:00:22 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

t_vector	cross_product(t_vector	v, t_vector	u)
{
	return (vector((v.y * u.z) - (u.y * v.z),
			(v.z * u.x) - (v.x * u.z),
			(v.x * u.y) - (v.y * u.x)));
}

float	dot_product(t_vector	v, t_vector	u)
{
	return ((v.x * u.x)
		+ (v.y * u.y)
		+ (v.z * u.z));
}

t_vector	add_vecs(t_vector	v, t_vector	u)
{
	return (vector((v.x + u.x),
			(v.y + u.y),
			(v.z + u.z)));
}

t_vector	sub_vecs(t_vector	v, t_vector	u)
{
	return (vector((v.x - u.x),
			(v.y - u.y),
			(v.z - u.z)));
}

t_vector	neg_vect(t_vector	v)
{
	return (vector((-1 * v.x),
			(-1 * v.y),
			(-1 * v.z)));
}
