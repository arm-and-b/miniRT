/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinet <abinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:41:09 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/08 18:05:52 by abinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

t_vector	multiply_vect(t_vector	v, float ratio)
{
	return (vector((ratio * v.x),
			(ratio * v.y),
			(ratio * v.z)));
}

t_vector	divide_vect(t_vector	v, float ratio)
{
	return (vector((v.x / ratio),
			(v.y / ratio),
			(v.z / ratio)));
}

t_point	point(float x, float y, float z)
{
	return ((t_point){x, y, z, 1.0});
}

t_vector	vector(float x, float y, float z)
{
	return ((t_vector){x, y, z, 0.0});
}

float	distance_points(t_point p1, t_point p2)
{
	return (sqrt(pow((p2.x - p1.x), 2)
			+ pow((p2.y - p1.y), 2)
			+ pow((p2.z - p1.z), 2)));
}
