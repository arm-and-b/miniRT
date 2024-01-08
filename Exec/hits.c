/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:14:04 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/05 18:45:06 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

t_intersect	*hit(t_world *world)
{
	t_intersect	*tmp;

	tmp = world->intersections;
	while (tmp && tmp->t < 0.00000)
		tmp = tmp->next;
	return (tmp);
}
