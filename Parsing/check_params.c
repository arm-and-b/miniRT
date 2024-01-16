/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinet <abinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 05:46:25 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/16 16:24:18 by abinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

static void	get_elements(char **element, t_world *world)
{
	if (tab_size(element) < 3)
		ft_error("Number of elements", true, world);
	if (!ft_strncmp(element[0], "A", 2) && !world->ambient.parsed)
		get_ambient(element, world);
	else if (!ft_strncmp(element[0], "C", 2) && !world->camera.parsed)
		get_camera(element, world);
	else if (!ft_strncmp(element[0], "L", 2) && !world->light.parsed)
		get_light(element, world);
	else if (!ft_strncmp(element[0], "sp", 3))
		get_sphere(element, world);
	else if (!ft_strncmp(element[0], "pl", 3))
		get_plane(element, world);
	else if (!ft_strncmp(element[0], "cy", 3))
		get_cylinder(element, world);
	else if (!ft_strncmp(element[0], "co", 2))
		get_cone(element, world);
	else
		ft_error("Parsing error", true, world);
}

static void	world_init(t_world	*world)
{
	world->garbage = ft_calloc(sizeof(t_list), 1);
	*world->garbage = NULL;
	world->parser = NULL;
	world->objects = ft_malloc(sizeof(t_element **), world);
	*world->objects = NULL;
	world->intersections = NULL;
	world->ambient.parsed = 0;
	world->light.parsed = 0;
	world->camera.parsed = 0;
}

void	check_args(int fd, t_world *world)
{
	char	*buffer;
	char	**element;

	world_init(world);
	buffer = get_next_line(fd, world);
	if (!buffer)
		ft_error("EMPTY SCENE", true, world);
	while (buffer)
	{
		if ((buffer[0] != '\n' && buffer[0] != '#') \
			&& ft_isalpha(buffer[0]))
		{
			element = ft_split(buffer, ' ', world);
			get_elements(element, world);
		}
		buffer = get_next_line(fd, world);
	}
	if (!world->ambient.parsed || !world->light.parsed || !world->camera.parsed)
		ft_error("Element Missing", true, world);
	close(fd);
}
