/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:32:54 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/15 21:02:58 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

bool	equal(float a, float b)
{
	return (fabs(a - b) < EPSILON);
}

int	convert(float color)
{
	if (color > 1)
		color = 1;
	color *= 255 + 0.5;
	return (color);
}

void	swap_float(float *a, float *b)
{
	float	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	print_vect(t_vector v)
{
	printf("x = %f\n", v.x);
	printf("y = %f\n", v.y);
	printf("z = %f\n", v.z);
	printf("w = %f\n\n\n", v.w);
}

void	print_matrix(t_matrix a)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < a.size)
	{
		j = 0;
		while (j < a.size)
		{
			printf("%.5f ", a.values[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n\n");
}
