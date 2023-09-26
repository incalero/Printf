/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:26:09 by incalero          #+#    #+#             */
/*   Updated: 2023/09/26 11:37:35 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	str_direccion(const void *ptr)
{
	char			str[20];
	unsigned long	direccion;
	char			*p;
	int				indice;
	int				i;

	if (!ptr)
		return (write(1, "0x0", 3));
	p = "0123456789abcdef";
	direccion = (unsigned long)ptr;
	indice = 19;
	i = indice;
	while (indice > 0 && direccion > 0)
	{
		i--;
		str[i] = p[direccion % 16];
		direccion /= 16;
	}
	if (i >= 2)
	{
		str[i - 1] = 'x';
		str[i - 2] = '0';
		i -= 2;
	}
	return (write (1, &str[i], indice - i));
}

int	put_hexa_x(unsigned int direccion)
{
	char	str[20];
	char	*p;
	int		indice;
	int		i;

	if (direccion == 0)
		return (write (1, "0", 1));
	p = "0123456789abcdef";
	indice = 19;
	str[indice] = '\0';
	i = indice;
	while (indice > 0 && direccion > 0)
	{
		i--;
		str[i] = p[direccion % 16];
		direccion /= 16;
	}
	return (write(1, &str[i], indice - i));
}

int	put_hexa_xup(unsigned int direccion)
{
	char	str[20];
	char	*p;
	int		indice;
	int		i;

	if (direccion == 0)
		return (write (1, "0", 1));
	p = "0123456789ABCDEF";
	indice = 19;
	i = indice;
	str[indice] = '\0';
	while (i > 0 && direccion > 0)
	{
		i--;
		str[i] = p[direccion % 16];
		direccion /= 16;
	}
	return (write (1, &str[i], indice - i));
}

int	ft_selected(char c, va_list args)
{
	int	res;

	res = 0;
	if (c == 'c')
		res = ft_putchar(va_arg(args, int));
	if (c == 's')
		res = ft_putstr(va_arg(args, char *));
	if (c == 'p')
		res = str_direccion((char *)va_arg(args, char *));
	if (c == 'd' || c == 'i')
		res = ft_putnbr(va_arg(args, int));
	if (c == 'u')
		res = ft_putnbr_unsigned(va_arg(args, unsigned int));
	if (c == 'x')
		res = put_hexa_x((va_arg(args, unsigned int)));
	if (c == 'X')
		res = put_hexa_xup(va_arg(args, unsigned int));
	if (c == '%')
		res = res + write(1, "%", 1);
	return (res);
}

int	ft_printf(char const *str, ...)
{
	int		len;
	int		res;
	va_list	args;

	len = 0;
	res = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[len])
	{
		if (str[len] == '%' && str[len + 1])
			res += ft_selected(str[len++ + 1], args);
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
