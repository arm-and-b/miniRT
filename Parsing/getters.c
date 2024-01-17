/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinet <abinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:03:18 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/17 14:41:55 by abinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

void	get_origin(t_point *origin, t_world *world)
{
	if (tab_size(world->parser) != 3)
		ft_error("Origin Elements", true, world);
	*origin = point(ft_atof(world->parser[0], world),
			ft_atof(world->parser[1], world),
			ft_atof(world->parser[2], world));
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
	world->camera.fov = ft_atof(element[3], world);
	if (world->camera.fov < 0 || world->camera.fov > 180)
		ft_error("Camera FOV", true, world);
	world->camera.parsed = true;
}

void	get_light(char **element, t_world *world)
{
	if (tab_size(element) != 4)
		ft_error("Light Elements", true, world);
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
	sp->sphere.rayon = ft_atof(element[2], world) / 2;
	if (sp->sphere.rayon <= 0.0000)
		ft_error("Sphere Diameter", true, world);
	get_color(element[3], world, &sp->color);
	sp->shininess = 200.0f;
	set_transform(sp, cross_matrices(translation(sp->sphere.origin.x, \
	sp->sphere.origin.y, sp->sphere.origin.z), scaling(sp->sphere.rayon, \
	sp->sphere.rayon, sp->sphere.rayon)));
	sp->type = SPHERE;
	sp->next = NULL;
	ft_add_back(world->objects, sp);
}

void	get_plane(char **element, t_world *world)
{
	t_element	*pl;

	if (tab_size(element) != 4)
		ft_error("Plane Elemnts", true, world);
	world->parser = ft_split(element[1], ',', world);
	if (tab_size(world->parser) != 3)
		ft_error("plane", true, world);
	pl = (t_element *)ft_malloc(sizeof(t_element), world);
	pl->plane.origin = point(ft_atof(world->parser[0], world),
			ft_atof(world->parser[1], world),
			ft_atof(world->parser[2], world));
	world->parser = ft_split(element[2], ',', world);
	if (tab_size(world->parser) != 3)
		ft_error("plane", true, world);
	pl->plane.orientation = vector(ft_atof(world->parser[0], world),
			ft_atof(world->parser[1], world),
			ft_atof(world->parser[2], world));
	get_color(element[3], world, &pl->color);
	set_transform(pl, cross_matrices(translation(pl->plane.origin.x,
				pl->plane.origin.y, pl->plane.origin.z),
			rotation_matrix(pl->plane.orientation)));
	pl->type = PLANE;
	pl->next = NULL;
	pl->shininess = 200.0f;
	ft_add_back(world->objects, pl);
}
