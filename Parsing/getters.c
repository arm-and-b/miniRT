/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:03:18 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/10 20:47:37 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

static void	get_origin(t_point *origin, t_world *world)
{
	*origin = point(ft_atof(world->parser[0], world),
			ft_atof(world->parser[1], world),
			ft_atof(world->parser[2], world));
}

static void	get_orientation(t_vector *orientation, t_world *world)
{
	*orientation = vector(ft_atof(world->parser[0], world),
			ft_atof(world->parser[1], world),
			ft_atof(world->parser[2], world));
	if ((orientation->x < -1 || orientation->x > 1)
		|| (orientation->y < -1 || orientation->y > 1)
		|| (orientation->z < -1 || orientation->z > 1))
		ft_error("Direction Vector", true, world);
}

void	get_ambient(char **element, t_world *world)
{
	if (world->ambient.parsed)
		ft_error("Too Many ambient Lights", true, world);
	if (tab_size(element) != 3)
		ft_error("Ambient Light Elements", true, world);
	world->ambient.brightness = ft_atof(element[1], world);
	if (world->ambient.brightness < 0.0 || world->ambient.brightness > 1.0)
		ft_error("Ambient Brightness", true, world);
	get_color(element[2], world, &world->ambient.colors);
	world->ambient.parsed = true;
}

void	get_camera(char **element, t_world *world)
{
	if (tab_size(element) != 4)
		ft_error("Camera Elements", true, world);
	world->parser = ft_split(element[1], ',', world);
	if (tab_size(world->parser) != 3)
		ft_error("Camera Origin", true, world);
	get_origin(&world->camera.origin, world);
	world->parser = ft_split(element[2], ',', world);
	if (tab_size(world->parser) != 3)
		ft_error("Camera Orientation", true, world);
	get_orientation(&world->camera.orientation, world);
	world->camera.fov = (int)ft_atof(element[3], world);
	if (world->camera.fov < 0 || world->camera.fov > 180)
		ft_error("Camera FOV", true, world);
	world->camera.parsed = true;
}


void	get_light(char **element, t_world *world)
{
	if (tab_size(element) != 4)
		ft_error("Light Elemets", true, world);
	world->parser = ft_split(element[1], ',', world);
	if (tab_size(world->parser) != 3)
		ft_error("Light origin", true, world);
	get_origin(&world->light.position, world);
	world->light.brightness = ft_atof(element[2], world);
	if (world->light.brightness < 0.0 || world->light.brightness > 1.0)
		ft_error("Light Brightness", true, world);
	get_color(element[3], world, &world->light.colors);
	world->light.parsed = true;
}

void	get_sphere(char **element, t_world *world)
{
	t_element	*sp;

	if (tab_size(element) != 4)
		ft_error("Sphere number of elements", true, world);
	world->parser = ft_split(element[1], ',', world);
	if (tab_size(world->parser) != 3)
		ft_error("Sphere Origin", true, world);
	sp = (t_element *)ft_malloc(sizeof(t_element), world);
	get_origin(&sp->sphere.origin, world);
	sp->sphere.diameter = ft_atof(element[2], world);
	if (sp->sphere.diameter <= 0.0000)
		ft_error("Sphere Diameter", true, world);
	sp->sphere.rayon = sp->sphere.diameter / 2;
	sp->material = material();
	get_color(element[3], world, &sp->material.color);
	sp->transform = translation(sp->sphere.origin.x, \
	sp->sphere.origin.y, sp->sphere.origin.z);
	sp->inverse = inverse(sp->transform);
	sp->type = 1;
	sp->next = NULL;
	ft_add_back(world->objects, sp);
}

void	get_plane(char **element, t_world *world)
{
	t_element	*plane;

	if (tab_size(element) != 4)
		ft_error("Plane Elemnts", true, world);
	world->parser = ft_split(element[1], ',', world);
	if (tab_size(world->parser) != 3)
		ft_error("plane", true, world);
	plane = (t_element *)ft_malloc(sizeof(t_element), world);
	plane->plane.origin = point(ft_atof(world->parser[0], world),
			ft_atof(world->parser[1], world),
			ft_atof(world->parser[2], world));
	world->parser = ft_split(element[2], ',', world);
	if (tab_size(world->parser) != 3)
		ft_error("plane", true, world);
	plane->plane.orientation = vector(ft_atof(world->parser[0], world),
			ft_atof(world->parser[1], world),
			ft_atof(world->parser[2], world));
	// plane->orient = normalize(plane->orient);
	// plane->transform = identity_matrix();
	plane->transform = translation(plane->plane.origin.x, \
	plane->plane.origin.y, plane->plane.origin.z);
	plane->inverse = inverse(plane->transform);
	plane->type = 2;
	plane->next = NULL;
	get_color(element[3], world, &plane->material.color);
	ft_add_back(world->objects, plane);
}
