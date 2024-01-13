/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:31:04 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/13 04:37:39 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

t_color	new_color(float r, float g, float b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color	add_colors(t_color	a, t_color	b)
{
	t_color	c;

	c.r = a.r + b.r;
	c.g = a.g + b.g;
	c.b = a.b + b.b;
	return (c);
}

t_color	mult_color(t_color	a, float b)
{
	t_color	c;

	c.r = a.r * b;
	c.g = a.g * b;
	c.b = a.b * b;
	return (c);
}

int	rgb(t_color color)
{
	return (convert(color.r) << 16
		| convert(color.g) << 8
		| convert(color.b));
}

void	print_color(t_color c)
{
	printf("r : %.4f\n", c.r);
	printf("g : %.4f\n", c.g);
	printf("b : %.4f\n\n", c.b);
}
