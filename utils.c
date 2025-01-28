/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evillca- <evillca-@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-28 16:05:03 by evillca-          #+#    #+#             */
/*   Updated: 2025-01-28 16:05:03 by evillca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_base(unsigned long long n, char *base, int base_len, int *count)
{
	char	number;

	if (n >= (unsigned long long)base_len)
		ft_base(n / base_len, base, base_len, count);
	number = base[n % base_len];
	*count += ft_putchar(number);
}

void	ft_putnbr(int nbr, int *count)
{
	long long int	n;

	n = nbr;
	if (n < 0)
	{
		*count += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10, count);
	*count += ft_putchar("0123456789"[n % 10]);
}

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	count = 0;
	if (!s)
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	i = 0;
	count = 0;
	while (s[i])
		count += ft_putchar(s[i++]);
	return (count);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
