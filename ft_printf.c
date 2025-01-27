#include "ft_printf.h"
#include <stdio.h>

int		ft_printf(char const *format, ...)
{
	int count;
	va_list argptr;

	count = 0;
	va_start(argptr, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1)) // if (*format == '%')
		{
			//format++;
			parse_format(++format,argptr, &count);
			//printf("|%s|",format);
		}
		else
			write(1, format, 1); // se puede cambiar por ft_putchar
		format++;
	}
	va_end(argptr);
	return (count);
}

static parse_format(char const *format, va_list argptr, int *count)
{
	
}

/*
va_list args; declara una variable para almacenar los argumentos.
va_start(args, format); inicializa args para que apunte al primer argumento variádico.
va_arg(args, type) obtiene el siguiente argumento del tipo especificado.
va_end(args); limpia args.
*/