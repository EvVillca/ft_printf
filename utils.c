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

void	print_base(unsigned long long n, char *base, int base_len, int *count)
{
	char	number;

	if (n >= (unsigned long long)base_len)
		print_base(n / base_len, base, base_len, count);
	number = base[n % base_len];
	*count += write(1, &number, 1);
}

void	ft_putnbr(int nbr, int *count)
{
	long long int	n;

	n = nbr;
	if (n < 0)
	{
		*count += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10, count);
	*count += write(1, &"0123456789"[n % 10], 1);
}

void	ft_putstr(char *str, int *count)
{
	if (!str)
	{
		*count += write(1, "(null)", 6);
		return ;
	}
	while (*str)
		*count += write(1, str++, 1);
}
