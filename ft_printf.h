/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evillca- <evillca-@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-28 16:01:27 by evillca-          #+#    #+#             */
/*   Updated: 2025-01-28 16:01:27 by evillca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char const *format, ...);
void	ft_putstr(char *str, int *count);
void	ft_putnbr(int nbr, int *count);
void	print_base(unsigned long long n, char *base, int base_len, int *count);

#endif