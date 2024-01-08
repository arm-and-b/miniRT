/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:30:19 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/06 22:17:46 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

void	ft_error(char *error, bool quit, t_world *world)
{
	printf("%s\n", error);
	if (quit)
	{
		if (world)
		{
			if (*world->garbage)
				ft_lstclear(world->garbage);
			if (world->garbage)
				free(world->garbage);
		}
		exit(1);
	}
}
