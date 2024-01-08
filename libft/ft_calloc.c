/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:49:17 by mbekouch          #+#    #+#             */
/*   Updated: 2023/04/02 12:09:58 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*mem;

	if (size && n > SIZE_MAX / size)
		return (NULL);
	mem = malloc(n * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, n * size);
	return (mem);
}
