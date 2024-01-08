/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 12:12:34 by mbekouch          #+#    #+#             */
/*   Updated: 2023/11/05 19:49:19 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unsize(size_t n, int base, bool pointer)
{
	int	i;
	int	nbr;

	nbr = (int)n;
	i = 0;
	if (pointer)
	{
		if (n == 0)
			return (1);
	}
	while (nbr != 0)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

int	ft_convert_hex(const char format, size_t nb)
{
	if (nb >= 16)
	{
		ft_convert_hex(format, nb / 16);
		ft_convert_hex(format, nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putcharf(nb + '0');
		else
		{
			if (nb > 9 && nb < 16)
			{
				if (format == 'x')
					ft_putcharf(nb - 10 + 'a');
				else if (format == 'X')
					ft_putcharf(nb - 10 + 'A');
			}	
		}
	}
	return (ft_unsize(nb, 16, false));
}

int	ft_convert_pointer(size_t nb)
{
	if (nb >= 16)
	{
		ft_convert_pointer(nb / 16);
		ft_convert_pointer(nb % 16);
	}
	else
	{
		if (ft_isdigit((int)nb))
			ft_putcharf(nb + '0');
		else
			ft_putcharf(nb - 10 + 'a');
	}
	return (ft_unsize(nb, 16, true));
}

char	*ft_unsigned_itoa(unsigned int nb)
{
	int		i;
	char	*str;

	i = ft_unsize(nb, 10, false);
	str = (char *)ft_calloc(sizeof(char), i + 1);
	if (!str)
		return (0);
	while (nb != 0)
	{
		str[i - 1] = (nb % 10 + '0');
		nb /= 10;
		i--;
	}
	return (str);
}

int	ft_put_unsigned(unsigned int nb)
{
	int		i;
	char	*str;

	if (nb == 0)
		return (ft_putcharf('0'));
	else
	{
		i = 0;
		str = ft_unsigned_itoa(nb);
		i += ft_putstrf(str);
		free(str);
	}
	return (i);
}
