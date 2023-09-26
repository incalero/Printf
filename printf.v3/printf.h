/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incalero <incalero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:44:11 by incalero          #+#    #+#             */
/*   Updated: 2023/09/21 15:50:20 by incalero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putnbr_unsigned(unsigned int n);
int	str_direccion (const void *ptr);
int	put_hexa_x (const void *ptr);
int	put_hexa_X (const void *ptr);
int	ft_selected(char c, va_list args);
int ft_printf(char const *str, ...);

#endif




