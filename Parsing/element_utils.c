/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:04:05 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/05 18:48:42 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

void	ft_add_back(t_element **lst, t_element *new)
{
	t_element	*i;

	if (*lst == NULL)
	{
		*lst = new;
		(*lst)->next = NULL;
		return ;
	}
	i = *lst;
	while (i->next)
		i = i->next;
	i->next = new;
	i->next->next = NULL;
}
