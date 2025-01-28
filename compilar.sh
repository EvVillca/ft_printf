#!/bin/bash

#cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl

## si hay exito al compilar que se muestre un mensaje


#cc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
echo "Compilando..."
#if cc ft_printf.c utils.c main.c -o printf
if cc *.c -o printf
then
	echo "Compilado con exito"
	echo ""
	echo "ejecutando..."
	#ejecutar el programa
	if ./printf
	then
		echo "Ejecutado con exito"
		echo ""
	else
		echo -e "\e[31mError al ejecutar\e[0m"
	fi
fi


