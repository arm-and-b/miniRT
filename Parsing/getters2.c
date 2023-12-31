/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:29:36 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/06 22:21:55 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"


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

// void	get_cylinder(char **element, t_world *world)
// {
// 	t_cylinder	*cylinder;

// 	if (tab_size(element) != 6)
// 		ft_error(PARS_CYL, true, world);
// 	world->parser = ft_split(element[1], ',', world);
// 	if (tab_size(world->parser) != 3)
// 		ft_error(PARS_CYL, true, world);
// 	cylinder = ft_malloc(sizeof(t_cylinder), world);
// 	cylinder->center_p = point(ft_atof(world->parser[0], world),
// 			ft_atof(world->parser[1], world),
// 			ft_atof(world->parser[2], world));
// 	world->parser = ft_split(element[2], ',', world);
// 	if (tab_size(world->parser) != 3)
// 		ft_error(PARS_CYL, true, world);
// 	cylinder->axis = vector(ft_atof(world->parser[0], world),
// 			ft_atof(world->parser[1], world),
// 			ft_atof(world->parser[2], world));
// 	cylinder->axis = normalize(cylinder->axis);
// 	cylinder->diameter = ft_atof(element[3], world);
// 	cylinder->height = ft_atof(element[4], world);
// 	if (cylinder->diameter <= 0.0 || cylinder->height <= 0.0)
// 		ft_error(PARS_CYL, true, world);
// 	get_color(element[5], world, &cylinder->colors);
// 	ft_add_back(world->objects, ft_newelement(Cylinder, cylinder, world));
// }
