/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:11:34 by abinet            #+#    #+#             */
/*   Updated: 2024/01/01 23:53:55 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

t_matrix	view_transform(t_vector from, t_vector to, t_vector up)
{
	t_matrix	orientation;
	t_vector	forward;
	t_vector	upn;
	t_vector	left;

	forward = normalize(sub_vecs(to, from));
	upn = normalize(up);
	left = cross_product(forward, upn);
	upn = cross_product(left, forward);
	orientation = (t_matrix){.size = 4, .values = {
	{left.x, left.y, left.z, 0},
	{upn.x, upn.y, upn.z, 0},
	{-forward.x, -forward.y, -forward.z, 0},
	{0, 0, 0, 1}
	}};
	return (cross_matrices(orientation,
			translation(-from.x, -from.y, -from.z)));
}

t_camera	new_camera(float hsize, float vsize, float fov)
{
	t_camera	camera;
	float		half_view;
	float		aspect;

	camera.hsize = hsize;
	camera.vsize = vsize;
	camera.fov = fov;
	camera.transform = identity_matrix();
	camera.inverse = inverse(camera.transform);
	half_view = tan(fov / 2);
	aspect = hsize / vsize;
	if (aspect >= 1)
	{
		camera.half_width = half_view;
		camera.half_height = half_view / aspect;
	}
	else
	{
		camera.half_width = half_view * aspect;
		camera.half_height = half_view;
	}
	camera.pixel_size = (camera.half_width * 2) / camera.hsize;
	return (camera);
}

t_ray	ray_for_pixel(t_camera c, int px, int py)
{
	float	offset[2];
	float	world_x;
	float	world_y;
	t_point	pixel;
	t_point	origin;

	offset[0] = (px + 0.5) * c.pixel_size;
	offset[1] = (py + 0.5) * c.pixel_size;
	world_x = c.half_width - offset[0];
	world_y = c.half_height - offset[1];
	pixel = vect_x_matrix(c.inverse, point(world_x, world_y, -1));
	pixel.w = 1.0;
	origin = vect_x_matrix(c.inverse, point(0, 0, 0));
	origin.w = 1.0;
	return (create_ray(origin, normalize(sub_vecs(pixel, origin))));
}
