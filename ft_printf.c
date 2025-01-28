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

static void	conver_pointer(char format, va_list argptr, int *count)
{
	unsigned long long	addr;

	if (format == 'p')
	{
		addr = va_arg(argptr, unsigned long long);
		if (addr == 0)
		{
			*count += write(1, "(nil)", 5);
			return ;
		}
		*count += write(1, "0x", 2);
		ft_base(addr, "0123456789abcdef", 16, count);
	}
}

static void	conver_numbers(char format, va_list argptr, int *count)
{
	if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(argptr, int), count);
	else if (format == 'u')
		ft_base(va_arg(argptr, unsigned int), "0123456789", 10, count);
	else if (format == 'x')
		ft_base(va_arg(argptr, unsigned int), "0123456789abcdef", 16, count);
	else if (format == 'X')
		ft_base(va_arg(argptr, unsigned int), "0123456789ABCDEF", 16, count);
}

static void	conver_format(char format, va_list argptr, int *count)
{
	if (format == 'c')
		*count += ft_putchar(va_arg(argptr, int));
	else if (format == 's')
		*count += ft_putstr(va_arg(argptr, char *));
	else if (format == 'p')
		conver_pointer(format, argptr, count);
	else if (format == 'd' || format == 'i' || format == 'u'
		|| format == 'x' || format == 'X')
		conver_numbers(format, argptr, count);
	else if (format == '%')
		*count += ft_putchar('%');
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
			conver_format(format[i], argptr, &count);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(argptr);
	return (count);
}
