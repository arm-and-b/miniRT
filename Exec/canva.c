/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canva.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:06:26 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/15 21:03:56 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

void	create_canva(t_world *world)
{
	world->mlx.mlx = mlx_init();
	world->mlx.img.img = mlx_new_image(world->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	world->mlx.img.addr = mlx_get_data_addr(world->mlx.img.img,
			&world->mlx.img.bpp, &world->mlx.img.line_length,
			&world->mlx.img.endian);
}

void	render(t_world *world)
{
	int			x;
	int			y;
	t_ray		ray;
	t_color		color;
	t_camera	camera;

	camera = new_camera(WIN_WIDTH, WIN_HEIGHT, radians(world->camera.fov));
	camera.transform = view_transform(world->camera.origin, \
	world->camera.orientation, vector(0, 1, 0));
	camera.inverse = inverse(camera.transform);
	y = 0;
	while (y < camera.vsize - 1)
	{
		ft_printf("\rRendering: %d%%", (int)((y + 2) * 100.0 / (camera.vsize)));
		x = 0;
		while (x < camera.hsize - 1)
		{
			ray = ray_for_pixel(camera, x, y);
			color = color_at(world, ray);
			write_pixel(world->mlx.img, x, y, rgb(color));
			x++;
		}
		y++;
	}
}

void	fill_in_image(t_world *world)
{
	render(world);
	world->mlx.win = mlx_new_window(world->mlx.mlx, WIN_WIDTH,
			WIN_HEIGHT, "MiniRT");
	mlx_put_image_to_window(world->mlx.mlx,
		world->mlx.win, world->mlx.img.img, 0, 0);
	mlx_hook(world->mlx.win, 17, 0, mlx_loop_end, world->mlx.mlx);
	mlx_key_hook(world->mlx.win, win_close, &world->mlx);
	mlx_loop(world->mlx.mlx);
}

int	win_close(int keycode, t_world *world)
{
	if (keycode == ESC)
		mlx_loop_end(world->mlx.mlx);
	return (0);
}

void	write_pixel(t_img image, unsigned int x,
	unsigned int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT)
		return ;
	dst = image.addr + (y * image.line_length + x * (image.bpp / 8));
	*(unsigned int *)dst = color;
}
