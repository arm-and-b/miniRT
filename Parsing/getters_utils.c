/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinet <abinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:14:05 by mbekouch          #+#    #+#             */
/*   Updated: 2024/01/16 17:04:17 by abinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MiniRT.h"

size_t	tab_size(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

bool	get_closed(char *parsing)
{
	if (!parsing)
		return (false);
	else
	{
		if (parsing[0] == '1')
			return (true);
		else
			return (false);
	}
}
