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
	ft_printf("- Caracter es %c\n", c);
	/*printf("- String: %s\n", str);
	printf("- Puntero: %p\n", ptr);
	printf("- Int d: %d, Int i: %i\n", 0, 521);
	printf("- Unsigned int: %u\n", 429496729);
	printf("- HEX minuscula:: %x\n", 255);
	printf("- HEX mayuscula: %X\n", 255);*/

	return (0);
}
