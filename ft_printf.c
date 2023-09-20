/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:26:09 by incalero          #+#    #+#             */
/*   Updated: 2023/09/20 10:22:57 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1 , &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		write (1 , &s[i++], 1);
}

void	ft_putnbr(int n)
{
	long int	x;

	x = n;
	if (x < 0)
	{
		ft_putchar('-');
		x = -x;
	}
	if (x >= 10)
	{
		ft_putnbr(x / 10);
		ft_putnbr(x % 10);
	}
	else
		ft_putchar(x + '0');
}

void	ft_putnbr_unsigned(unsigned int n)
{
	long int	x;

	x = n;

	if (x >= 10)
	{
		ft_putnbr(x / 10);
		ft_putnbr(x % 10);
	}
	else
		ft_putchar(x + '0');
}

void	str_direccion (const void *ptr)
{
	char str[16];  // Buffer para almacenar la dirección en formato hexadecimal
    unsigned long long direccion;
	char	*p;

	p = "0123456789abcdef";
	direccion = (unsigned long long)ptr;
	int indice = sizeof(str) -1;
	str[indice] = '\0';

	while (indice > 0 && direccion > 0) 
	{
        indice--;
    	str[indice] = p[direccion % 16];
        direccion /= 16;
    }
	if (indice >= 2) 
	{
        str[indice - 1] = 'x';
        str[indice - 2] = '0';
        indice -= 2;
    }
	write(1, str + indice, sizeof(str) - indice);

}

void	put_hexa_x (const void *ptr)
{
	char str[16];  // Buffer para almacenar la dirección en formato hexadecimal
    unsigned long long direccion;
	char	*p;

	p = "0123456789abcdef";
	direccion = (unsigned long long)ptr;
	int indice = sizeof(str) -1;
	str[indice] = '\0';

	while (indice > 0 && direccion > 0) 
	{
        indice--;
    	str[indice] = p[direccion % 16];
        direccion /= 16;
    }
	
	write(1, str + indice, sizeof(str) - indice);

}



int	ft_selected(char c, va_list args)
{
	if (c == 'c')
	{
		char	c;
		
		c = va_arg(args, int);
		ft_putchar(c);
		return(1);
	}
	if (c == 's')
	{
		char	*str;
		
		str = va_arg(args, char*);
		ft_putstr(str);
	}

	if (c == 'p')
	{
		char	*str;
		
		str = (char*)va_arg(args, const void *);
		str_direccion (str);
		return(0);
	}

	if (c == 'd' || c == 'i')
	{
		int	c;
		
		c = va_arg(args, int);
		ft_putnbr(c);
		return(1);
	}

	if (c == 'u')
	{
		unsigned int	c;
		
		c = va_arg(args, unsigned int);
		ft_putnbr_unsigned(c);
		return(0);
	}

	if (c == 'x' || c == 'X')
	{
		char	*str;
		
		str = (char*)va_arg(args, const void *);
		put_hexa_x (str);
		return(0);
	}

	if (c == '%')
	{
		write(1, "%", 1);
		return(1);
	}
	
	return(0);		
}

int ft_printf(char const *str, ...)
{
	int	len;
	int res;
	
	va_list	args;
	
	len = 0;
	res = 0;

	va_start(args, str);
	
	while (str[len])
	{
		if (str[len] == '%')
		{
			res = res + ft_selected(str[len +1], args);
			len++;
		}
		else 
		{
			res++;
			write(1, &str[len], 1);
		}
		len++;
	}
	
    /*va_list args_copy;
    va_copy(args_copy, args);*/

	va_end(args);
	return (0);

}

int main(void)
{
	char	*c;
	char	a;
	int		b;
	unsigned int	d;
	unsigned int	e;
	int	i;
	int	j;
	
	a = 'a';
	c = "abcde";
	b = -15674;
	d = -1267;
	e = 42;
	
	i = ft_printf("%c", a);
	j = printf("%c", a);
	printf("\n");
	
	printf("es esto i? %i\n", i);
	printf("es esto j? %i\n", j);
	printf("prinf: %i\n", (printf("%c", a)));
	
	/*printf(" y printf me devuelve %i\n", printf("el resultado de printf es: %c", 'a'));*/
	

	
	ft_printf("el string es:      %s\n", c);
	printf("el string en p es: %s\n", c);
	printf("\n");
	
	ft_printf("el numero es:      %d\n", b);
	printf("el numero en p es: %d\n", b);
	printf("\n");

	ft_printf("el numero es:      %i\n", b);
	printf("el numero en p es: %i\n", b);
	printf("\n");
	
	ft_printf("el numero positivo es:      %u\n", d);
	printf("el numero positivo en p es: %u\n", d);
	printf("\n");

	ft_printf("el numero positivo es:      %u\n", e);
	printf("el numero positivo en p es: %u\n", e);
	printf("\n");

	ft_printf("el caracter es:      %%\n");
	printf("el caracter en p es: %%\n");
	printf("\n");
	
	ft_printf("el la direccion de memoria es:       %p\n", c);
	printf("el la direccion de memoria con p es: %p\n", c);
	printf("\n");

	ft_printf("el numero %u " ,e); 
	ft_printf("en hexadecimal es: %x\n", e);
	printf("el numero %u " ,e); 
	printf("en printf en hexadecimal es: %x\n", e);

	return(0);
	
	
}
