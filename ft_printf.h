
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int		ft_printf(char const *format, ...);
void	ft_putstr(char *str, int *count);
void	ft_putnbr(int nbr, int *count);
void	print_base(unsigned long long n, char *base, int base_len, int *count);

#endif