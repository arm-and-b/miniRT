/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:03:57 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/06 22:21:34 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t	size, t_world *world)
{
	void	*addr;
	t_list	*new;

	addr = ft_calloc(1, size);
	if (!addr)
		ft_error("MEMORY ALLOCATION FAILED", true, world);
	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = addr;
	new->next = NULL;
	ft_lstadd_back(world->garbage, new);
	return (addr);
}
