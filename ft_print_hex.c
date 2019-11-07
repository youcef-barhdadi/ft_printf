/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:30:39 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/11/07 15:38:48 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*getrightformat(int status, long long n)
{
	char *str;

	if (status == UPPER)
		str = ft_lltoa_base(n, LARGEHEX);
	else
		str = ft_lltoa_base(n, SMALLHEX);
	return (str);
}

static void		printhelp(t_printf *print, int precision, char chartoprint)
{
	while (print->width-- - precision > 0)
	{
		write(1, &chartoprint, 1);
		print->count++;
	}
}

void			print_hex(t_printf *print, va_list list, int status)
{
	long long	n;
	char		*str;
	int			precision;

	n = va_arg(list, long long);
	str = getrightformat(status, n);
	precision = print->precision == 0 ? ft_strlen(str) : print->precision;
	printhelp(print, precision, print->zero ? '0' : ' ');
	while (print->precision > 0 && print->precision-- > (int)ft_strlen(str))
	{
		write(1, "0", 1);
		print->count++;
	}
	ft_putstr_fd(str, 1);
	print->count += ft_strlen(str);
	printhelp(print, precision, print->zero ? '0' : ' ');
}
