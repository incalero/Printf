/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:06:08 by incalero          #+#    #+#             */
/*   Updated: 2023/09/25 11:12:34 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i] != '\0')
		write (1, &s[i++], 1);
	return (i);
}

int	ft_putnbr(int n)
{
	long int	x;
	int			count;

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
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	long int	x;
	int			count;

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
	return (count);
}
