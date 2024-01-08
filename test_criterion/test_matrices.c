/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrices.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:33:50 by yde-goes          #+#    #+#             */
/*   Updated: 2024/01/01 23:59:38 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../MiniRT.h"

/*	Constructing and inspecting a 4x4 matrix */
Test(matrices, create_values_4x4)
{
	t_matrix	m = (t_matrix){
		.size = 4,
		.values = 
		{{1, 2, 3, 4},
		{5.5, 6.5, 7.5, 8.5},
		{9, 10, 11, 12},
		{13.5, 14.5, 15.5, 16.5}},
	};

	cr_assert(eq(flt, m.values[0][0], 1));
	cr_assert(eq(flt, m.values[0][1], 2));
	cr_assert(eq(flt, m.values[0][2], 3));
	cr_assert(eq(flt, m.values[0][3], 4));

	cr_assert(eq(flt, m.values[1][0], 5.5));
	cr_assert(eq(flt, m.values[1][1], 6.5));
	cr_assert(eq(flt, m.values[1][2], 7.5));
	cr_assert(eq(flt, m.values[1][3], 8.5));

	cr_assert(eq(flt, m.values[2][0], 9));
	cr_assert(eq(flt, m.values[2][1], 10));
	cr_assert(eq(flt, m.values[2][2], 11));
	cr_assert(eq(flt, m.values[2][3], 12));

	cr_assert(eq(flt, m.values[3][0], 13.5));
	cr_assert(eq(flt, m.values[3][1], 14.5));
	cr_assert(eq(flt, m.values[3][2], 15.5));
	cr_assert(eq(flt, m.values[3][3], 16.5));
}

/*	Constructing and inspecting a 2x2 matrix */
Test(matrices, create_values_2x2)
{
	t_matrix	m = (t_matrix){
		.size = 2,
		.values =
		{{-3, 5},
		{1, -2}},
	};

	cr_assert(eq(flt, m.values[0][0], -3));
	cr_assert(eq(flt, m.values[0][1], 5));
	cr_assert(eq(flt, m.values[1][0], 1));
	cr_assert(eq(flt, m.values[1][1], -2));
}

/*	Constructing and inspecting a 3x3 matrix */
Test(matrices, create_values_3x3)
{
	t_matrix	m = (t_matrix){
		. size = 3,
		.values = 
		{{-3, 5, 0},
		{1, -2, -7},
		{0, 1, 1}},
	};

	cr_assert(eq(flt, m.values[0][0], -3));
	cr_assert(eq(flt, m.values[0][1], 5));
	cr_assert(eq(flt, m.values[0][2], 0));

	cr_assert(eq(flt, m.values[1][0], 1));
	cr_assert(eq(flt, m.values[1][1], -2));
	cr_assert(eq(flt, m.values[1][2], -7));

	cr_assert(eq(flt, m.values[2][0], 0));
	cr_assert(eq(flt, m.values[2][1], 1));
	cr_assert(eq(flt, m.values[2][2], 1));
}

/*	Multiplying two matrices */
Test(matrices, multiply_mx_mx)
{
	t_matrix	c;

	t_matrix	a = (t_matrix){
		.size = 4,
		.values = {{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 8, 7, 6},
		{5, 4, 3, 2}},
	};

	t_matrix	b = (t_matrix){
		.size = 4,
		.values =
		{{-2, 1, 2, 3},
		{3, 2, 1, -1},
		{4, 3, 6, 5},
		{1, 2, 7, 8}},
	};

	c = cross_matrices(a, b);

	cr_assert(eq(flt, c.values[0][0], 20));
	cr_assert(eq(flt, c.values[0][1], 22));
	cr_assert(eq(flt, c.values[0][2], 50));
	cr_assert(eq(flt, c.values[0][3], 48));

	cr_assert(eq(flt, c.values[1][0], 44));
	cr_assert(eq(flt, c.values[1][1], 54));
	cr_assert(eq(flt, c.values[1][2], 114));
	cr_assert(eq(flt, c.values[1][3], 108));

	cr_assert(eq(flt, c.values[2][0], 40));
	cr_assert(eq(flt, c.values[2][1], 58));
	cr_assert(eq(flt, c.values[2][2], 110));
	cr_assert(eq(flt, c.values[2][3], 102));

	cr_assert(eq(flt, c.values[3][0], 16));
	cr_assert(eq(flt, c.values[3][1], 26));
	cr_assert(eq(flt, c.values[3][2], 46));
	cr_assert(eq(flt, c.values[3][3], 42));
}

/*	Multipliying 4x4 values by a tuple */
Test(matrices, multiply_tp_mx)
{
	t_matrix	a = (t_matrix){
		.size = 4,
		.values =
		{{1, 2, 3, 4},
		{2, 4, 4, 2},
		{8, 6, 4, 1},
		{0, 0, 0, 1}},
	};
	t_point	b;
	t_point	c;

	b = point(1, 2, 3);
	c = vect_x_matrix(a, b);

	cr_assert(eq(flt, c.x, 18));
	cr_assert(eq(flt, c.y, 24));
	cr_assert(eq(flt, c.z, 33));
	cr_assert(eq(flt, c.w, 1));

	t_vector	d;
	t_vector	e;

	d = vector(1, 2, 3);
	e = vect_x_matrix(a, b);
	e.w = 0.0;

	cr_assert(eq(flt, e.x, 18));
	cr_assert(eq(flt, e.y, 24));
	cr_assert(eq(flt, e.z, 33));
	cr_assert(eq(flt, e.w, 0));
}

Test(matrices, rotation_x)
{
	t_point	p;
	t_point	result;
	t_matrix m;

	m = rotation_x(M_PI_4);
	p = point(0, 1, 0);
	result = vect_x_matrix(inverse(m), p);

	cr_assert_float_eq(result.x, 0, EPSILON);
	cr_assert_float_eq(result.y, sqrtf(2)/2, EPSILON);
	cr_assert_float_eq(result.z, -sqrtf(2)/2, EPSILON);
	cr_assert_float_eq(result.w, 1, EPSILON);
}

/*	Multipliying a 4x4 values by the identity matrix */
Test(matrices, multiply_by_identity_matrix)
{
	t_matrix	id = identity_matrix();
	t_matrix	c;

	t_matrix	a = (t_matrix){
		.size = 4,
		.values =
		{{0, 1, 2, 4},
		{1, 2, 4, 8},
		{2, 4, 8, 16},
		{4, 8, 16, 32}},
	};

	c = cross_matrices(a, id);

	cr_assert(eq(flt, c.values[0][0], 0));
	cr_assert(eq(flt, c.values[0][1], 1));
	cr_assert(eq(flt, c.values[0][2], 2));
	cr_assert(eq(flt, c.values[0][3], 4));

	cr_assert(eq(flt, c.values[1][0], 1));
	cr_assert(eq(flt, c.values[1][1], 2));
	cr_assert(eq(flt, c.values[1][2], 4));
	cr_assert(eq(flt, c.values[1][3], 8));

	cr_assert(eq(flt, c.values[2][0], 2));
	cr_assert(eq(flt, c.values[2][1], 4));
	cr_assert(eq(flt, c.values[2][2], 8));
	cr_assert(eq(flt, c.values[2][3], 16));

	cr_assert(eq(flt, c.values[3][0], 4));
	cr_assert(eq(flt, c.values[3][1], 8));
	cr_assert(eq(flt, c.values[3][2], 16));
	cr_assert(eq(flt, c.values[3][3], 32));
}

/*	Transposing a matrix */
Test(matrices, transpose)
{
	t_matrix	a = (t_matrix){
		.size = 4,
		.values = {{0, 9, 3, 0},
		{9, 8, 0, 8},
		{1, 8, 5, 3},
		{0, 0, 5, 8}},
	};
	t_matrix	c;

	c = transpose(a);
	transpose(c);

	cr_assert(eq(flt, c.values[0][0], 0));
	cr_assert(eq(flt, c.values[0][1], 9));
	cr_assert(eq(flt, c.values[0][2], 1));
	cr_assert(eq(flt, c.values[0][3], 0));

	cr_assert(eq(flt, c.values[1][0], 9));
	cr_assert(eq(flt, c.values[1][1], 8));
	cr_assert(eq(flt, c.values[1][2], 8));
	cr_assert(eq(flt, c.values[1][3], 0));

	cr_assert(eq(flt, c.values[2][0], 3));
	cr_assert(eq(flt, c.values[2][1], 0));
	cr_assert(eq(flt, c.values[2][2], 5));
	cr_assert(eq(flt, c.values[2][3], 5));

	cr_assert(eq(flt, c.values[3][0], 0));
	cr_assert(eq(flt, c.values[3][1], 8));
	cr_assert(eq(flt, c.values[3][2], 3));
	cr_assert(eq(flt, c.values[3][3], 8));
}

/*
*	Transposition of an identity matrix should be an..
*	identity matrix!
*/
Test(matrices, transpose_of_identity_matrix)
{
	t_matrix	a = (t_matrix){
		.size = 4,
		.values = {{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}},
	};

	t_matrix	id;
	id = transpose(a);

	cr_assert(eq(flt, id.values[0][0], 1));
	cr_assert(eq(flt, id.values[0][1], 0));
	cr_assert(eq(flt, id.values[0][2], 0));
	cr_assert(eq(flt, id.values[0][3], 0));

	cr_assert(eq(flt, id.values[1][0], 0));
	cr_assert(eq(flt, id.values[1][1], 1));
	cr_assert(eq(flt, id.values[1][2], 0));
	cr_assert(eq(flt, id.values[1][3], 0));

	cr_assert(eq(flt, id.values[2][0], 0));
	cr_assert(eq(flt, id.values[2][1], 0));
	cr_assert(eq(flt, id.values[2][2], 1));
	cr_assert(eq(flt, id.values[2][3], 0));

	cr_assert(eq(flt, id.values[3][0], 0));
	cr_assert(eq(flt, id.values[3][1], 0));
	cr_assert(eq(flt, id.values[3][2], 0));
	cr_assert(eq(flt, id.values[3][3], 1));
}

/* 	Calculating the determinant of a 2x2 matrix */
Test(matrices, determinant_2x2)
{
	t_matrix	a = (t_matrix){
		.size = 2,
		.values =
		{{1, 5},
		{-3, 2}},
	};
	float		result;

	result = determinant(a);
	cr_assert(eq(int, result, 17));
}

/*	A submatrix of a 3x3 matrix is a 2x2 matrix */
Test(matrices, submatrix_of_3x3)
{
	t_matrix	a = (t_matrix) {
	.size = 3,
	.values = {
		{1, 5, 0},
		{-3, 2, 7},
		{0, 6, -3},
	}};
	t_matrix	result;

	result = submatrix(a, 0, 2);

	cr_assert(eq(flt, result.size, 2));
	cr_assert(eq(flt, result.values[0][0], -3));
	cr_assert(eq(flt, result.values[0][1], 2));

	cr_assert(eq(flt, result.values[1][0], 0));
	cr_assert(eq(flt, result.values[1][1], 6));
}

/*	A submatrix of a 4x4 matrix is a 3x3 matrix */
Test(matrices, submatrix_of_4x4)
{
	t_matrix	a = (t_matrix) {
	.size = 4,
	.values = {
		{-6, 1, 1, 6},
		{-8, 5, 8, 6},
		{-1, 0, 8, 2},
		{-7, 1, -1, 1},
	}};
	t_matrix	result;

	result = submatrix(a, 2, 1);

	cr_assert(eq(flt, result.size, 3));
	cr_assert(eq(flt, result.values[0][0], -6));
	cr_assert(eq(flt, result.values[0][1], 1));
	cr_assert(eq(flt, result.values[0][2], 6));

	cr_assert(eq(flt, result.values[1][0], -8));
	cr_assert(eq(flt, result.values[1][1], 8));
	cr_assert(eq(flt, result.values[1][2], 6));

	cr_assert(eq(flt, result.values[2][0], -7));
	cr_assert(eq(flt, result.values[2][1], -1));
	cr_assert(eq(flt, result.values[2][2], 1));
}

/*	Calculating a minor of a 3x3 matrix */
Test(matrices, minor_of_3x3)
{
	t_matrix	a = (t_matrix) {
	.size = 3,
	.values = {
		{3, 5, 0},
		{2, -1, 7},
		{6, -1, 5},
	}};
	float		result;

	result = minor(a, 0, 0);
	cr_assert(eq(flt, result, 2));

	result = minor(a, 1, 0);
	cr_assert(eq(flt, result, 25));
}

/*	Calculating a cofactor of a 3x3 matrix */
Test(matrices, cofactor_of_3x3)
{
	t_matrix	a = (t_matrix) {
	.size = 3,
	.values = {
		{3, 5, 0},
		{2, -1, 7},
		{6, -1, 5},
	}};
	float		result;

	result = cofactor(a, 0, 0);
	cr_assert(eq(flt, result, 2));

	result = cofactor(a, 1, 0);
	cr_assert(eq(flt, result, -25));
}

/*	Calculating the determinant of a 3x3 matrix */
Test(matrices, determinant_of_3x3)
{
	t_matrix	a = (t_matrix) {
	.size = 3,
	.values = {
		{1, 2, 6},
		{-5, 8, -4},
		{2, 6, 4},
	}};
	float		result;

	result = cofactor(a, 0, 0);
	cr_assert(eq(flt, result, 56));

	result = cofactor(a, 0, 1);
	cr_assert(eq(flt, result, 12));

	result = cofactor(a, 0, 2);
	cr_assert(eq(flt, result, -46));

	result = determinant(a);
	cr_assert(eq(flt, result, -196));
}

/*	Calculating the determinant of a 4x4 matrix */
Test(matrices, determinant_of_4x4)
{
	t_matrix	a = (t_matrix) {
		.size = 4,
		.values = {
		{-2, -8, 3, 5},
		{-3, 1, 7, 3},
		{1, 2, -9, 6},
		{-6, 7, 7, -9}},
	};
	float		result;

	result = cofactor(a, 0, 0);
	cr_assert(eq(flt, result, 690));

	result = cofactor(a, 0, 1);
	cr_assert(eq(flt, result, 447));
	
	result = cofactor(a, 0, 2);
	cr_assert(eq(flt, result, 210));

	result = cofactor(a, 0, 3);
	cr_assert(eq(flt, result, 51));

	result = determinant(a);
	cr_assert(eq(flt, result, -4071));
}

/*	Testing an invertible values for invertibility */
Test(matrices, is_invertible_4x4)
{
	float		result;
	t_matrix	a = (t_matrix) {
		.size = 4,
		.values = {
		{6, 4, 4, 4},
		{5, 5, 7, 6},
		{4, -9, 3, -7},
		{9, 1, 7, -6}},
	};

	result = determinant(a);
	cr_assert(eq(flt, result, -2120));
	cr_assert(eq(int, true, is_invertible(a)));
}

/*	Testing a noninvertible values for invertibility */
Test(matrices, is_not_invertible_4x4)
{
	t_matrix	a = (t_matrix) {
		.size = 4,
		.values ={
		{-4, 2, -2, -3},
		{9, 6, 2, 6},
		{0, -5, 1, -5},
		{0, 0, 0, 0},
	}};
	float		result;

	result = determinant(a);
	cr_assert(eq(flt, result, 0));
	cr_assert(eq(int, false, is_invertible(a)));
}

/*	Calculating the inverse of a matrix */
Test(matrices, get_inverse_1)
{
	t_matrix	a = (t_matrix){
		.size = 4,
		.values = {
		{-5, 2, 6, -8},
		{1, -5, 1, 8},
		{7, 7, -6, -7},
		{1, -3, 7, 4}},
	};
	t_matrix	b;
	float		result;

	b = inverse(a);

	result = determinant(a);
	cr_assert(eq(flt, result, 532));

	result = cofactor(a, 2, 3);
	cr_assert(eq(flt, result, -160));
	cr_assert(eq(flt, b.values[3][2], (float) -160/532));

	result = cofactor(a, 3, 2);
	cr_assert(eq(flt, result, 105));
	cr_assert(eq(flt, b.values[2][3], (float) 105/532));

	cr_assert_float_eq(b.values[0][0], 0.21805, EPSILON);
	cr_assert_float_eq(b.values[0][1], 0.45113, EPSILON);
	cr_assert_float_eq(b.values[0][2], 0.24060, EPSILON);
	cr_assert_float_eq(b.values[0][3], -0.04511, EPSILON);

	cr_assert_float_eq(b.values[1][0], -0.80827, EPSILON);
	cr_assert_float_eq(b.values[1][1], -1.45677, EPSILON);
	cr_assert_float_eq(b.values[1][2], -0.44361, EPSILON);
	cr_assert_float_eq(b.values[1][3], 0.52068, EPSILON);

	cr_assert_float_eq(b.values[2][0], -0.07895, EPSILON);
	cr_assert_float_eq(b.values[2][1], -0.22368, EPSILON);
	cr_assert_float_eq(b.values[2][2], -0.05263, EPSILON);
	cr_assert_float_eq(b.values[2][3], 0.19737, EPSILON);

	cr_assert_float_eq(b.values[3][0], -0.52256, EPSILON);
	cr_assert_float_eq(b.values[3][1], -0.81391, EPSILON);
	cr_assert_float_eq(b.values[3][2], -0.30075, EPSILON);
	cr_assert_float_eq(b.values[3][3], 0.30639, EPSILON);
}

/*	Calculating the inverse of another matrix */
Test(matrices, get_inverse_2)
{
	t_matrix	a = (t_matrix) {
		.size = 4,
		.values = {
		{8, -5, 9, 2},
		{7, 5, 6, 1},
		{-6, 0, 9, 6},
		{-3, 0, -9, -4},
	}};
	t_matrix	b;
	
	b = inverse(a);

	cr_assert_float_eq(b.values[0][0], -0.15385, EPSILON);
	cr_assert_float_eq(b.values[0][1], -0.15385, EPSILON);
	cr_assert_float_eq(b.values[0][2], -0.28205, EPSILON);
	cr_assert_float_eq(b.values[0][3], -0.53846, EPSILON);

	cr_assert_float_eq(b.values[1][0], -0.07692, EPSILON);
	cr_assert_float_eq(b.values[1][1], 0.12308, EPSILON);
	cr_assert_float_eq(b.values[1][2], 0.02564, EPSILON);
	cr_assert_float_eq(b.values[1][3], 0.03077, EPSILON);

	cr_assert_float_eq(b.values[2][0], 0.35897, EPSILON);
	cr_assert_float_eq(b.values[2][1], 0.35897, EPSILON);
	cr_assert_float_eq(b.values[2][2], 0.43590, EPSILON);
	cr_assert_float_eq(b.values[2][3], 0.92308, EPSILON);

	cr_assert_float_eq(b.values[3][0], -0.69231, EPSILON);
	cr_assert_float_eq(b.values[3][1], -0.69231, EPSILON);
	cr_assert_float_eq(b.values[3][2], -0.76923, EPSILON);
	cr_assert_float_eq(b.values[3][3], -1.92308, EPSILON);
}

/*	Calculating the inverse of a third matrix */
Test(matrices, get_inverse_3)
{
	t_matrix	a = (t_matrix){
		.size = 4,
		.values = {
		{9, 3, 0, 9},
		{-5, -2, -6, -3},
		{-4, 9, 6, 4},
		{-7, 6, 6, 2},
	}};
	t_matrix	b;
	
	b = inverse(a);

	cr_assert_float_eq(b.values[0][0], -0.04074, EPSILON);
	cr_assert_float_eq(b.values[0][1], -0.07778, EPSILON);
	cr_assert_float_eq(b.values[0][2], 0.14444, EPSILON);
	cr_assert_float_eq(b.values[0][3], -0.22222, EPSILON);

	cr_assert_float_eq(b.values[1][0], -0.07778, EPSILON);
	cr_assert_float_eq(b.values[1][1], 0.03333, EPSILON);
	cr_assert_float_eq(b.values[1][2], 0.36667, EPSILON);
	cr_assert_float_eq(b.values[1][3], -0.33333, EPSILON);

	cr_assert_float_eq(b.values[2][0], -0.02901, EPSILON);
	cr_assert_float_eq(b.values[2][1], -0.14630, EPSILON);
	cr_assert_float_eq(b.values[2][2], -0.10926, EPSILON);
	cr_assert_float_eq(b.values[2][3], 0.12963, EPSILON);

	cr_assert_float_eq(b.values[3][0], 0.17778, EPSILON);
	cr_assert_float_eq(b.values[3][1], 0.06667, EPSILON);
	cr_assert_float_eq(b.values[3][2], -0.26667, EPSILON);
	cr_assert_float_eq(b.values[3][3], 0.33333, EPSILON);
}

/*	Multiplying a product by its inverse */
Test(matrices, mult_product_by_its_inverse)
{
	t_matrix	c;
	t_matrix	result;

	t_matrix	a = (t_matrix){
		.size = 4,
		.values =
		{{3, -9, 7, 3},
		{3, -8, 2, -9},
		{-4, 4, 4, 1},
		{-6, 5, -1, 1},
	}};
	t_matrix	b = (t_matrix){
		.size = 4,
		.values = 
		{{8, 2, 2, 2},
		{3, -1, 7, 0},
		{7, 0, 5, 4},
		{6, -2, 0, 5},
	}};

	c = cross_matrices(a, b);
	result = cross_matrices(c, inverse(b));

	cr_assert_float_eq(result.values[0][0], 3, EPSILON);
	cr_assert_float_eq(result.values[0][1], -9, EPSILON);
	cr_assert_float_eq(result.values[0][2], 7, EPSILON);
	cr_assert_float_eq(result.values[0][3], 3, EPSILON);

	cr_assert_float_eq(result.values[1][0], 3, EPSILON);
	cr_assert_float_eq(result.values[1][1], -8, EPSILON);
	cr_assert_float_eq(result.values[1][2], 2, EPSILON);
	cr_assert_float_eq(result.values[1][3], -9, EPSILON);

	cr_assert_float_eq(result.values[2][0], -4, EPSILON);
	cr_assert_float_eq(result.values[2][1], 4, EPSILON);
	cr_assert_float_eq(result.values[2][2], 4, EPSILON);
	cr_assert_float_eq(result.values[2][3], 1, EPSILON);

	cr_assert_float_eq(result.values[3][0], -6, EPSILON);
	cr_assert_float_eq(result.values[3][1], 5, EPSILON);
	cr_assert_float_eq(result.values[3][2], -1, EPSILON);
	cr_assert_float_eq(result.values[3][3], 1, EPSILON);
}
