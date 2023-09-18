/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:26:09 by incalero          #+#    #+#             */
/*   Updated: 2023/09/18 15:54:54 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_selected(char c, va_list args)
{
	if (c == 'c')
	{
		char	c;
		
		c = va_arg(args, int);
		write(1, &c, 1);
		return(1);
	}
	if (c == 's')
	{
		char	*str;
		
		str = va_arg(args, char*);
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
	char	c;
	c = 'abcd';

	ft_printf("el caracter es: %c", c);
	return(0);
	
	
}
