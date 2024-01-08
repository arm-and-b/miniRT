/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:23:37 by mbekouch          #+#    #+#             */
/*   Updated: 2023/12/05 20:38:34 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2, t_world *world)
{
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	dest = ft_malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1), world);
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s1, ft_strlen(s1));
	ft_memcpy(dest + ft_strlen(s1), s2, ft_strlen(s2));
	return (dest);
}
