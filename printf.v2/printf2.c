/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:02:52 by incalero          #+#    #+#             */
/*   Updated: 2023/09/18 12:04:40 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/* La función print formatted, imprime un mensaje por pantalla utilizando una cadena de formato que incluye 
   diversos tipos de instrucciones para mezclar multiples cadenas en la cadena final a mostrar por pantalla.*/

int	ft_printf(const char *s, ...)
{
	int		x;
	int		count;
	/*La variable tipo va_list args es la que vamos a utilizar para almacenar los argumentos que existan.*/
	va_list	args;

	x = 0;
	count = 0;
	/* Va_start establece arg_s en el primer argumento opcional de la lista de argumentos que se pasa a la función. Es 
	   necesario usar va_start antes de usar va_arg por primera vez. Basicamente lo que hace es integrar nuestros argumentos.*/
	va_start(args, s);

	/* Mientras exista contenido en nuestro puntero s*/
	while (s[x])
	{
		/* Aquí entramos al if conforme encontremos un %, el cualposteriormente definiremos que hara.*/
		if (s[x] == '%')
		{
			/* Este avanza por la string y en base a lo que haya seguido del porcentaje, ya sea %x, %c, %u, etc, se decidirá que hacer.*/
			x++;
			count = ft_porcentaje(s[x], args, count);
		}
		/* En caso de que no encontremos ningún %, nos dedicaremos a escribir lo que haya dentro de lo indicado por nuestro puntero s.*/
		else
		{
			count++;
			write(1, &s[x], 1);
		}
		x++;
	}
	/* Una vez que hayamos recuperado todos nuestros argumentos,escribimos va_end(args), para establecer nuestro puntero 
	   a null. Es necesario escribirlo ya que emos inicializado los argumentos con va_start.*/
	va_end(args);
	/*Por ultimo devuelve la cantidad total de caracteres escritos.*/
	return (count);
}