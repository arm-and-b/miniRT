/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 12:23:37 by mbekouch          #+#    #+#             */
/*   Updated: 2023/11/06 21:56:43 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putcharf(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstrf(char	*str)
{
	int	i;

	i = 0;
	if (!str)
		return (write (1, "(null)", 6));
	while (str[i])
		ft_putcharf(str[i++]);
	return (i);
}

int	ft_size(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbrf(int nb)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		ft_putcharf('-');
		nbr = -nb;
	}
	else
		nbr = nb;
	if (nbr < 10)
		ft_putcharf(nbr + '0');
	else
	{
		ft_putnbrf(nbr / 10);
		ft_putnbrf(nbr % 10);
	}
	return (ft_size(nb));
}
