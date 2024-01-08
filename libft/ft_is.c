/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:31:51 by mbekouch          #+#    #+#             */
/*   Updated: 2023/11/13 21:32:31 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'));
}

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9') || c == '.' || c == '-' || c == '+');
}

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
