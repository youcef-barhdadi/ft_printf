/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:08:05 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/11/07 15:37:28 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printhelper(t_printf *print, int precision, char chartoprint)
{
	while (print->width-- - precision > 0)
	{
		write(1, &chartoprint, 1);
		print->count++;
	}
}

void		print_unsigned(t_printf *print, va_list list)
{
	char		*str;
	int			len;
	char		chartoprint;
	int			precision;
	unsigned	nbr;

	chartoprint = ' ';
	nbr = va_arg(list, unsigned);
	str = ft_utoa(nbr);
	len = ft_strlen(str);
	precision = print->precision == 0 ? len : print->precision;
	if (print->zero)
		chartoprint = '0';
	if (print->direction == LEFT)
		printhelper(print, precision, chartoprint);
	while (print->precision > 0 && print->precision-- > len)
	{
		write(1, "0", 1);
		print->count++;
	}
	ft_putstr_fd(str, 1);
	print->count += ft_strlen(str);
	if (print->direction == RIGHT)
		printhelper(print, precision, chartoprint);
}
