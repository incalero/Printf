/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:26:09 by incalero          #+#    #+#             */
/*   Updated: 2023/09/21 15:50:17 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putchar(char c)
{
	write(1 , &c, 1);
	return(1);
}

int	ft_putstr(char *s)
{
	int	i;
	
	if(!s)
	{
		write(1, "(null)", 6);
		return(6);
	}

	i = 0;
	while (s[i] != '\0')
		write (1 , &s[i++], 1);
	return(i);
}

int	ft_putnbr(int n)
{
	long int	x;
	int	count;
	
	count = 0;
	x = n;
	while (x < 0)
	{
		ft_putchar('-');
		x = -x;
		count++;
	}
	if (x >= 10)
	{
		count += ft_putnbr(x / 10);
		count += ft_putnbr(x % 10);
	}
	else
	{
		ft_putchar(x + '0');
		count++;
	}
	return(count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	long int	x;
	int count;

	x = n;
	count = 0;
	if (x >= 10)
	{
		count += ft_putnbr(x / 10);
		count += ft_putnbr(x % 10);
	}
	else
	{
		ft_putchar(x + '0');
		count++;
	}
	return(count);
}

int	str_direccion (const void *ptr)
{
	char str[16];  // Buffer para almacenar la dirección en formato hexadecimal
    unsigned long long direccion;
	char	*p;

	if (!ptr)
	{
		write(1, "0x0", 3);
		return(3);
	}
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
	return(sizeof(str) - indice -1);
}

int	put_hexa_x (const void *ptr)
{
	char str[16]; 
    unsigned long long direccion;
	char	*p;
	
	if (!ptr)
		return(0);
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
	return(sizeof(str) - indice -1);
}

int	put_hexa_X (const void *ptr)
{
	char str[16]; 
    unsigned long long direccion;
	char	*p;
	
	if (!ptr)
		return(0);
	p = "0123456789ABCDEF";
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
	return(sizeof(str) - indice -1);
}

int	ft_selected(char c, va_list args)
{
	int	res;
	
	res = 0;
	if (c == 'c')
		ft_putchar(va_arg(args, int));
	if (c == 's')
		res = res + ft_putstr(va_arg(args, char*));
	if (c == 'p')
		res = res + str_direccion ((char*)va_arg(args, const void *));
	if (c == 'd' || c == 'i')
		res = res + ft_putnbr(va_arg(args, int));
	if (c == 'u')
		res = res + ft_putnbr_unsigned(va_arg(args, unsigned int));
	if (c == 'x')
		res = res + put_hexa_x ((char*)va_arg(args, const void *));
	if (c == 'X')
		res = res + put_hexa_X ((char*)va_arg(args, const void *));
	if (c == '%')
		res = res + write(1, "%", 1);
	return(res);		
}

int ft_printf(char const *str, ...)
{
	int	len;
	int res;
	va_list	args;
	
	len = 0;
	res = 0;
	if (!str)
		return(0);
	va_start(args, str);
	while (str[len])
	{
		if (str[len] == '%')
			res = res + ft_selected(str[len++ +1], args);
		else 
		{
			res++;
			write(1, &str[len], 1);
		}
		len++;
	}
	va_end(args);
	return (res);

}

/*int main(void)
{
	char	*c;
	char	a;
	int		b;
	unsigned int	d;
	unsigned int	e;
	int	i;
	int	j;
	int l;
	int k;
	
	a = 'a';
	c = "abcdesowwwdwt";
	b = -15674;
	d = -1267;
	e = 423;
	
	i = ft_printf("%%");
	j = printf("%%");
	printf("\n");

	l = ft_printf("%x", e);
	k = printf("%x",e);
	printf("\n");
	
	printf(" y printf me devuelve %i\n", printf("el resultado de printf es: %c", 'a'));
	

	printf("es esto l? %i\n", l);
	printf("es esto k? %i\n", k);
	printf("prinf: %i\n", (printf("%s", c)));
	
	
	ft_printf("el numero positivo es:      %u\n", d);
	printf("el numero positivo en p es: %u\n", d);
	printf("\n");

	ft_printf("el caracter es:      %%\n");
	printf("el caracter en p es: %%\n");
	printf("\n");
	
	ft_printf("el la direccion de memoria es:       %p\n", c);
	printf("el la direccion de memoria con p es: %p\n", c);
	printf("\n");

	printf("es esto i? %i\n", i);
	printf("es esto j? %i\n", j);
	printf("prinf: %i\n", (printf("%p", c)));

	ft_printf("el numero %u " ,e); 
	ft_printf("en hexadecimal es: %x\n", e);
	printf("el numero %u " ,e); 
	printf("en printf en hexadecimal es: %x\n", e);

	ft_printf("el numero %u " ,e); 
	ft_printf("en hexadecimal es: %X\n", e);
	
	printf("el numero %u" ,e); 
	printf("en printf en hexadecimal es: %X\n", e);

	return(0);
	
	
}*/
