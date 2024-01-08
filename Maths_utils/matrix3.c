/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:16:52 by mbekouch          #+#    #+#             */
/*   Updated: 2023/12/15 22:08:47 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

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
