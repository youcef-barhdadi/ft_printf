/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:08:31 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/11/07 15:37:20 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_right(t_printf *print, int len)
{
	if (print->direction == RIGHT)
		while (print->width-- - len > 0)
		{
			write(1, " ", 1);
			print->count++;
		}
}

void			print_pointer(t_printf *print, va_list list)
{
	size_t	p;
	char	*str;
	char	*hex;
	int		len;

	p = (size_t)va_arg(list, void *);
	str = ft_ulltoa_base(p, SMALLHEX);
	hex = ft_strjoin("0x", str);
	len = ft_strlen(hex);
	if (print->direction == LEFT)
		while (print->width-- - len > 0)
		{
			write(1, " ", 1);
			print->count++;
		}
	while (print->precision > 0 && print->precision-- > len)
	{
		write(1, "0", 1);
		print->count++;
	}
	ft_putstr_fd(hex, 1);
	print->count += ft_strlen(hex);
	print_right(print, len);
	free(hex);
	free(str);
}
