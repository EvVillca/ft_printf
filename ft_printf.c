/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evillca- <evillca-@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-28 15:55:48 by evillca-          #+#    #+#             */
/*   Updated: 2025-01-28 15:55:48 by evillca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conver_pointer(unsigned long long addr)
{
	int					count;

	count = 0;
	if (addr == 0)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	count += write(1, "0x", 2);
	count += ft_base(addr, "0123456789abcdef", 16);
	return (count);
}

static int	conver_numbers(char format, va_list argptr)
{
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(argptr, int)));
	else if (format == 'u')
		return (ft_base(va_arg(argptr, unsigned int), "0123456789", 10));
	else if (format == 'x')
		return (ft_base(va_arg(argptr, unsigned int), "0123456789abcdef", 16));
	else if (format == 'X')
		return (ft_base(va_arg(argptr, unsigned int), "0123456789ABCDEF", 16));
	return (0);
}

static int	conver_format(char format, va_list argptr)
{
	if (format == 'c')
		return (ft_putchar(va_arg(argptr, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(argptr, char *)));
	else if (format == 'p')
		return (conver_pointer(va_arg(argptr, unsigned long long)));
	else if (format == 'd' || format == 'i' || format == 'u'
		|| format == 'x' || format == 'X')
		return (conver_numbers(format, argptr));
	else if (format == '%')
		return (ft_putchar('%'));
	return (1);
}

int	ft_printf(char const *format, ...)
{
	int		count;
	int		i;
	va_list	argptr;

	count = 0;
	va_start(argptr, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += conver_format(format[i], argptr);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(argptr);
	return (count);
}
