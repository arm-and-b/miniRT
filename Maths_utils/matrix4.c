/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinet <abinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:07:19 by mbekouch          #+#    #+#             */
/*   Updated: 2023/12/11 21:35:32 by abinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

float	minor(t_matrix a, int del_row, int del_col)
{
	return (determinant(submatrix(a, del_row, del_col)));
}

float	cofactor(t_matrix a, int del_row, int del_col)
{
	if (is_odd_nbr(del_row + del_col) == false)
		return (minor(a, del_row, del_col));
	else
		return (minor(a, del_row, del_col) * -1);
}

t_matrix	inverse(t_matrix	m)
{
	t_matrix	n;
	float		det;
	size_t		row;
	size_t		col;

	det = determinant(m);
	if (!is_invertible(m) || m.size <= 0 || det == 0.0)
		return (m);
	n.size = m.size;
	row = 0;
	while (row < m.size)
	{
		col = 0;
		while (col < m.size)
		{
			n.values[col][row] = cofactor(m, row, col) / det;
			col++;
		}
		row++;
	}
	return (n);
}

t_matrix	shearing(float x[2], float y[2], float z[2])
{
	return ((t_matrix){
		.size = 4,
		.values = {{1, x[0], x[1], 0},
			{y[0], 1, y[1], 0},
			{z[0], z[1], 1, 0},
			{0, 0, 0, 1}}
	});
}
