/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:57:56 by mbekouch          #+#    #+#             */
/*   Updated: 2023/04/02 12:12:17 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_case(va_list args, const char format)
{
	int		i;
	size_t	p;

	i = 0;
	if (format == 's')
		i += ft_putstrf(va_arg(args, char *));
	if (format == 'c')
		i += ft_putcharf(va_arg(args, int));
	if ((format == 'i') || (format == 'd'))
		i += ft_putnbrf(va_arg(args, int));
	if (format == '%')
		i += ft_putcharf('%');
	if ((format == 'x') || (format == 'X'))
		i += ft_convert_hex(format, va_arg(args, unsigned int));
	if (format == 'u')
		i += ft_put_unsigned(va_arg(args, unsigned int));
	if (format == 'p')
	{
		p = va_arg(args, size_t);
		if (p)
			i += ft_putstrf("0x") + ft_convert_pointer(p);
		else
			i += ft_putstrf("(nil)");
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_case(args, str[i + 1]);
			i++;
		}
		else
			count += ft_putcharf(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
