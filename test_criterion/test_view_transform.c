/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_view_transform.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:28:50 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/12/14 22:12:14 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"
#include "utils.h"

/*
 * This test checks if the function "view_transform" correctly transforms the
 * default orientation of the camera.
 */
Test(view_transformation, transform_default_orientation)
{
	t_point		from;
	t_point		to;
	t_vector	up;
	t_matrix	t;
	int		result;

	from = point(0, 0, 0);
	to = point(0, 0, -1);
	up = vector(0, 1, 0);
	t = view_transform(from, to, up);

	result = is_matrix_equal(t, identity_matrix());
	cr_assert(eq(i32, result, 1));
}

/*
 * This checks if the function "view_transform" correctly transforms the camera
 * when looking in the positive z direction.
 */
Test(view_transformation, looking_in_positive_z)
{
	t_point		from;
	t_point		to;
	t_vector	up;
	t_matrix	t;
	int		result;

	from = point(0, 0, 0);
	to = point(0, 0, 1);
	up = vector(0, 1, 0);
	t = view_transform(from, to, up);

	result = is_matrix_equal(t, scaling(-1, 1, -1));
	cr_assert(eq(i32, result, 1));
}

/*
 * This checks if the function "view_transform" correctly moves the world when
 * the camera is moved.
 */
Test(view_transformation, moves_the_world)
{
	t_point		from;
	t_point		to;
	t_vector	up;
	t_matrix	t;
	int		result;

	from = point(0, 0, 8);
	to = point(0, 0, 0);
	up = vector(0, 1, 0);
	t = view_transform(from, to, up);

	result = is_matrix_equal(t, translation(0, 0, -8));
	cr_assert(eq(i32, result, 1));
}

/*
 * This checks if the function "view_transform" correctly transforms the camera
 * with an arbitrary transformation.
 */
Test(view_transformation, arbitrary_transformation)
{
	t_point		from;
	t_point		to;
	t_vector	up;
	t_matrix	t;
	int		result;

	t_matrix	expected = {
		.size = 4,
		.values = {
		{-0.50709, 0.50709,  0.67612, -2.36643},
		{ 0.76772, 0.60609,  0.12122, -2.82843},
		{-0.35857, 0.59761, -0.71714,  0.00000},
		{ 0.00000, 0.00000,  0.00000,  1.00000},
		}
	};

	from = point(1, 3, 2);
	to = point(4, -2, 8);
	up = vector(1, 1, 0);
	t = view_transform(from, to, up);

	result = is_matrix_equal(t, translation(0, 0, -8));
	assert_matrix_equal(t, expected);
}
