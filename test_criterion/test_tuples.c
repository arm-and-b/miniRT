/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tuples.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 23:09:37 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/01 23:21:02 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"
#include "utils.h"

Test(point, create_a_point)
{
	t_point	p;

	p = point(4.2, -4.2, 3.2);
	cr_assert(eq(flt, p.x, 4.2));
	cr_assert(eq(flt, p.y, -4.2));
	cr_assert(eq(flt, p.z, 3.2));
	cr_assert(eq(flt, p.w, 1.0));

	p = point(0.7, -8.6, 3.2);
	cr_assert(eq(flt, p.x, 0.7));
	cr_assert(eq(flt, p.y, -8.6));
	cr_assert(eq(flt, p.z, 3.2));
	cr_assert(eq(flt, p.w, 1.0));
}
Test(vector, create_a_vector)
{
	t_vector	p;

	p = vector(2.1, -1.9, 0.8);
	cr_assert(eq(flt, p.x, 2.1));
	cr_assert(eq(flt, p.y, -1.9));
	cr_assert(eq(flt, p.z, 0.8));
	cr_assert(eq(flt, p.w, 0.0));

	p = vector(4.2, -1.9, 3.2);
	cr_assert(eq(flt, p.x, 4.2));
	cr_assert(eq(flt, p.y, -1.9));
	cr_assert(eq(flt, p.z, 3.2));
	cr_assert(eq(flt, p.w, 0.0));
}

Test(points, adding_points)
{
	t_point	a;
	t_point	b;
	t_point	result;

	a = point(3, -2, 5);
	b = point(-2, 3, 1);
	result = a + b;
	result = point(result.x, result.y, result.z);
	cr_assert(eq(flt, result.x, 1));
	cr_assert(eq(flt, result.y, 1));
	cr_assert(eq(flt, result.z, 6));
	cr_assert(eq(flt, result.w, 1));
}

Test(vectors, adding_vectors)
{
	t_vector	a;
	t_vector	b;
	t_vector	result;

	a = vector(3, -2, 5);
	b = vector(-2, 3, 1);
	result = a + b;
	cr_assert(eq(flt, result.x, 1));
	cr_assert(eq(flt, result.y, 1));
	cr_assert(eq(flt, result.z, 6));
	cr_assert(eq(flt, result.w, 0));
}
