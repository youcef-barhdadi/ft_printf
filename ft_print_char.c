/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 18:43:02 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/11/07 15:36:11 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printhelp(t_printf *print, char chartoprint, int precision)
{
	while (print->width-- - precision - 1 > 0)
	{
		write(1, &chartoprint, 1);
		print->count++;
	}
}

void		print_char(t_printf *print, va_list list, int prec)
{
	char	toprint;
	char	chartoprint;
	int		precision;

	precision = print->precision == 0 ? print->precision : 1;
	chartoprint = ' ';
	if (!prec)
		toprint = va_arg(list, int);
	else
		toprint = '%';
	if (print->zero)
		chartoprint = '0';
	if (print->direction == LEFT)
		printhelp(print, chartoprint, precision);
	write(1, &toprint, 1);
	print->count++;
	if (print->direction == RIGHT)
		while (print->width-- - 1 > 0)
		{
			write(1, " ", 1);
			print->count++;
		}
}
