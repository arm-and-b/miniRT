/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinet <abinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:16:52 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/14 23:54:36 by abinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

static void	calculate_rotation_angles(t_vector vec, float *x, float *z)
{
	float	ratio;

	ratio = sqrtf((vec.x * vec.x) + (vec.y * vec.y));
	if (fabs(ratio) < EPSILON)
		*z = M_PI_2;
	else
		*z = cosf(vec.y / ratio);
	if (fabs(ratio) < EPSILON)
		*x = cosf(EPSILON);
	else
		*x = cosf(ratio);
}

t_matrix	rotation_matrix(t_vector vector)
{
	float		x_angle;
	float		z_angle;
	t_matrix	rotate_z;
	t_matrix	rotate_x;
	t_matrix	full_rotation;

	calculate_rotation_angles(vector, &x_angle, &z_angle);
	rotate_z = rotation_z(z_angle);
	rotate_x = rotation_x(x_angle);
	full_rotation = cross_matrices(rotate_z, rotate_x);
	return (full_rotation);
}

t_matrix	rotation_x(float rad)
{
	return ((t_matrix){
		.size = 4,
		.values = {{1, 0.00000, 0.00000, 0.00000},
			{0.00000, cosf(rad), -sinf(rad), 0.00000},
			{0.00000, sinf(rad), cosf(rad), 0.00000},
			{0.00000, 0.00000, 0.00000, 1}}
	});
}

t_matrix	rotation_y(float rad)
{
	return ((t_matrix){
		.size = 4,
		.values = {{cosf(rad), 0.00000, sinf(rad), 0.00000},
			{0.00000, 1, 0.00000, 0.00000},
			{-sinf(rad), 0.00000, cosf(rad), 0.00000},
			{0.00000, 0.00000, 0.00000, 1}}
	});
}

t_matrix	rotation_z(float rad)
{
	return ((t_matrix){
		.size = 4,
		.values = {{cosf(rad), -sinf(rad), 0.00000, 0.00000},
			{sinf(rad), cosf(rad), 0.00000, 0.00000},
			{0.00000, 0.00000, 1, 0.00000},
			{0.00000, 0.00000, 0.00000, 1}}
	});
}
