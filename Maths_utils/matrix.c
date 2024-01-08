/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:38:15 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/01 23:44:55 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

t_matrix	cross_matrices(t_matrix a, t_matrix b)
{
	t_matrix	c;
	int			row;
	int			col;

	c.size = fmin(a.size, b.size);
	row = -1;
	while (++row < fmax(a.size, b.size))
	{
		col = -1;
		while (++col < fmax(a.size, b.size))
			c.values[row][col] = a.values[row][0] * b.values[0][col]
				+ a.values[row][1] * b.values[1][col]
				+ a.values[row][2] * b.values[2][col]
				+ a.values[row][3] * b.values[3][col];
	}
	return (c);
}

t_vector	vect_x_matrix(t_matrix a, t_vector b)
{
	t_vector	result;

	result.x = (a.values[0][0] * b.x) + (a.values[0][1] * b.y) \
		+ (a.values[0][2] * b.z) + (a.values[0][3] * b.w);
	result.y = a.values[1][0] * b.x + (a.values[1][1] \
		* b.y) + (a.values[1][2] * b.z) + (a.values[1][3] * b.w);
	result.z = (a.values[2][0] * b.x) + (a.values[2][1] \
		* b.y) + (a.values[2][2] * b.z) + (a.values[2][3] * b.w);
	result.w = (a.values[3][0] * b.x) + (a.values[3][1] \
		* b.y) + (a.values[3][2] * b.z) + (a.values[3][3] * b.w);
	return (result);
}

t_matrix	transpose(t_matrix	a)
{
	t_matrix	b;
	size_t		row;
	size_t		col;

	b.size = a.size;
	row = 0;
	while (row < b.size)
	{
		col = 0;
		while (col < b.size)
		{
			b.values[col][row] = a.values[row][col];
			col++;
		}
		row++;
	}
	return (b);
}

t_matrix	submatrix(t_matrix a, size_t del_row, size_t del_col)
{
	size_t			row;
	size_t			col;
	t_matrix		sub;

	if (del_col < 0 || del_col > a.size
		|| del_row < 0 || del_row > a.size || a.size == 2)
		return (a);
	row = 0;
	while (row < a.size - 1)
	{
		col = 0;
		while (col < a.size - 1)
		{
			sub.values[row][col]
				= a.values[row + (row >= del_row)][col + (col >= del_col)];
			col++;
		}
		row++;
	}
	sub.size = a.size - 1;
	return (sub);
}

float	determinant(t_matrix	a)
{
	size_t		col;
	float		determin;

	determin = 0;
	if (a.size == 2)
		determin = (a.values[0][0] * a.values[1][1])
			- (a.values[0][1] * a.values[1][0]);
	else
	{
		col = 0;
		while (col < a.size)
		{
			determin += (a.values[0][col] * cofactor(a, 0, col));
			col++;
		}
	}
	return (determin);
}
