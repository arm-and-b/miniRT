/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:59:29 by mbekouch          #+#    #+#             */
/*   Updated: 2023/12/10 00:08:20 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

t_matrix	identity_matrix(void)
{
	return ((t_matrix){
		.size = 4,
		.values = {{1, 0, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 1}}
	});
}

t_matrix	translation(float x, float y, float z)
{
	return ((t_matrix){
		.size = 4,
		.values = {{1, 0, 0, x},
			{0, 1, 0, y},
			{0, 0, 1, z},
			{0, 0, 0, 1}}
	});
}

t_matrix	scaling(float x, float y, float z)
{
	return ((t_matrix){
		.size = 4,
		.values = {{x, 0, 0, 0},
			{0, y, 0, 0},
			{0, 0, z, 0},
			{0, 0, 0, 1}}
	});
}

bool	is_matrix_equal(t_matrix a, t_matrix b)
{
	int	row;
	int	col;

	row = -1;
	if (a.size != b.size)
		return (false);
	while (++row < 4)
	{
		col = -1;
		while (++col < 4)
		{
			if (!equal(a.values[row][col], b.values[row][col]))
				return (false);
		}
	}
	return (true);
}
