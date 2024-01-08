/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:28:15 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/08 21:07:06 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

static int	ft_open(char *argv)
{
	int		fd;

	if (ft_strncmp(argv + (ft_strlen(argv) - 3), ".rt", 3))
		return (printf("ERROR : WRONG FILE TYPE\n"), exit(1), -1);
	if (open(argv, __O_DIRECTORY) >= 0)
		return (printf("ERROR : '%s' IS A DIRECTORY\n", argv), exit(1), -1);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (printf("ERROR : CANNOT OPEN '%s'\n", argv), exit(1), -1);
	return (fd);
}

int	main(int argc, char **argv)
{
	t_world	world;

	if (argc != 2)
		return (printf("ERROR : WRONG NUMBER OF ARGUMENTS\n"), 1);
	check_args(ft_open(argv[1]), &world);
	create_canva(&world);
	fill_in_image(&world);
	destroy_canva(&world);
	ft_lstclear(world.garbage);
	free(world.garbage);
	return (0);
}
