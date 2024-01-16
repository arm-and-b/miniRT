/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinet <abinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:29:36 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/16 17:06:15 by abinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

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

void	get_color(char *element, t_world *world, t_color *colors)
{
	world->parser = ft_split(element, ',', world);
	if (tab_size(world->parser) != 3
		|| !ft_strncmp(world->parser[tab_size(world->parser) - 1], "", 1))
		ft_error("Color Elements", true, world);
	colors->r = ft_atof(world->parser[0], world) / 255;
	colors->g = ft_atof(world->parser[1], world) / 255;
	colors->b = ft_atof(world->parser[2], world) / 255;
	if ((colors->r < 0 || colors->r > 1)
		|| (colors->g < 0 || colors->g > 1)
		|| (colors->b < 0 || colors->b > 1))
		ft_error("Color Values", true, world);
}

void	get_orientation(t_vector *orientation, t_world *world)
{
	if (tab_size(world->parser) != 3)
		ft_error("Orientation Elements", true, world);
	*orientation = vector(ft_atof(world->parser[0], world),
			ft_atof(world->parser[1], world),
			ft_atof(world->parser[2], world));
	if ((orientation->x != -1 && orientation->x != 1 && orientation->x != 0)
		|| (orientation->y != -1 && orientation->y != 1 && orientation->y != 0)
		|| (orientation->z != -1 && orientation->z != 1 && orientation->z != 0))
		ft_error("Direction Vector", true, world);
}

void	get_cylinder(char **element, t_world *world)
{
	t_element	*cy;

	if (tab_size(element) != 6 && tab_size(element) != 7)
		ft_error("cy element", true, world);
	cy = ft_malloc(sizeof(t_element), world);
	world->parser = ft_split(element[1], ',', world);
	get_origin(&cy->cylinder.origin, world);
	world->parser = ft_split(element[2], ',', world);
	get_orientation(&cy->cylinder.axis, world);
	cy->material = material(world);
	get_color(element[5], world, &cy->material.color);
	cy->cylinder.radius = (ft_atof(element[3], world) / 2);
	cy->cylinder.height = ft_atof(element[4], world);
	if (cy->cylinder.radius <= 0.0 || cy->cylinder.height <= 0.0)
		ft_error("cyl diameter", true, world);
	set_transform(cy, cross_matrices(\
	translation(cy->cylinder.origin.x, cy->cylinder.origin.y, \
	cy->cylinder.origin.z), cross_matrices(rotation_matrix(cy->cylinder.axis), \
	scaling(cy->cylinder.radius, 1, cy->cylinder.radius))));
	cy->type = CYLINDER;
	cy->cylinder.minimum = -cy->cylinder.height / 2;
	cy->cylinder.maximum = cy->cylinder.height / 2;
	cy->cylinder.closed = get_closed(element[6]);
	cy->next = NULL;
	ft_add_back(world->objects, cy);
}

void	get_cone(char **element, t_world *world)
{
	t_element	*cone;

	if (tab_size(element) != 6 && tab_size(element) != 7)
		ft_error("cone element", true, world);
	cone = ft_malloc(sizeof(t_element), world);
	world->parser = ft_split(element[1], ',', world);
	get_origin(&cone->cone.origin, world);
	world->parser = ft_split(element[2], ',', world);
	get_orientation(&cone->cone.axis, world);
	cone->material = material(world);
	get_color(element[5], world, &cone->material.color);
	cone->cone.rayon = (ft_atof(element[3], world) / 2);
	cone->cone.height = ft_atof(element[4], world);
	if (cone->cone.rayon <= 0.0 || cone->cone.height <= 0.0)
		ft_error("cone diameter", true, world);
	set_transform(cone, cross_matrices(\
	translation(cone->cone.origin.x, cone->cone.origin.y, \
	cone->cone.origin.z), cross_matrices(rotation_matrix(cone->cone.axis), \
	scaling(cone->cone.rayon, cone->cone.height, cone->cone.rayon))));
	cone->type = CONE;
	cone->cone.minimum = -cone->cone.height / 2;
	cone->cone.maximum = cone->cone.height / 2;
	cone->cone.closed = get_closed(element[6]);
	cone->next = NULL;
	ft_add_back(world->objects, cone);
}
