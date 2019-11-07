/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:22:22 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/11/07 15:37:33 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			init(t_printf *print)
{
	print->count = 0;
	print->direction = LEFT;
	print->zero = 0;
	print->width = 0;
	print->skip = 0;
	print->precision = 0;
	print->dot = 0;
}

static void		handle(t_printf *print, char f, va_list list)
{
	char		*string;

	if (f == 's')
	{
		string = va_arg(list, char *);
		print_string(string, print);
	}
	else if (f == 'd' || f == 'i')
		print_int(print, list);
	else if (f == 'c')
		print_char(print, list, 0);
	else if (f == 'p')
		print_pointer(print, list);
	else if (f == 'x' || f == 'X')
		f == 'x' ? print_hex(print, list, LOWER) :
			print_hex(print, list, UPPER);
	else if (f == 'u')
		print_unsigned(print, list);
	else
	{
		write(1, &f, 1);
		print->count++;
	}
}

static void		realprintf(t_printf *print, const char *format,
				va_list list, int *count)
{
	int			i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			init(print);
			proccessflags(format + i, print, list);
			i += print->skip;
			if (format[i] == '%')
				print_char(print, list, 1);
			else
				handle(print, format[i], list);
			*count += print->count;
		}
		else if (format[i])
		{
			write(1, &format[i], 1);
			(*count)++;
		}
		i++;
	}
}

int				ft_printf(const char *format, ...)
{
	int			i;
	int			count;
	va_list		list;
	t_printf	*print;

	count = 0;
	print = malloc(sizeof(t_printf));
	if (!print)
		return (-1);
	i = 0;
	va_start(list, format);
	realprintf(print, format, list, &count);
	va_end(list);
	free(print);
	return (count);
}
