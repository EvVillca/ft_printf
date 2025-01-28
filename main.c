#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char			*str;
	char			c;
	int 	x;
	void	 *ptr;

	c = 'E';
	str = "I'am Super E";
	x = 1234;
	ptr = &x;

	printf("- Caracter es %c\n", c);
	ft_printf("- Caracter es %c\n\n", c);

	printf("- String: %s\n", str);
	ft_printf("- String: %s\n\n", str);

	printf("- String: %s\n", NULL);
	ft_printf("- String: %s\n\n", NULL);

	printf("- Puntero: %p\n", ptr);
	ft_printf("- Puntero: %p\n\n", ptr);
	printf("- Puntero: %p\n", NULL);
	ft_printf("- Puntero: %p\n\n", NULL);

	printf("- Int d: %d, Int i: %i\n", 0, 521);
	ft_printf("- Int d: %d, Int i: %i\n\n", 0, 521);

	printf("- Unsigned int: %u\n", 429496729);
	ft_printf("- Unsigned int: %u\n\n", 429496729);

	printf("- HEX minuscula:: %x\n", 255);
	ft_printf("- HEX minuscula:: %x\n\n", 255);

	printf("- HEX mayuscula: %X\n", 255);
	ft_printf("- HEX mayuscula: %X\n\n", 255);

	printf("- Caracter es %%\n");
	ft_printf("- Caracter es %%\n\n");

	return (0);
}
