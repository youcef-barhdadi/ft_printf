/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proccessflags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 12:22:11 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/11/07 15:38:29 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		skip(const char *f, char toskip)
{
	int i;

	i = 0;
	while (f[i] == toskip && f[i])
		i++;
	return (i);
}

static int		handlewidth(const char *f, t_printf *print, va_list list)
{
	int i;

	i = 0;
	if (ft_isdigit(f[i]))
	{
		print->width = ft_atoi(f + i);
		while (ft_isdigit(f[i]) && f[i])
			i++;
	}
	else if (f[i] == '*')
	{
		print->width = va_arg(list, int);
		if (print->width < 0)
		{
			print->direction = RIGHT;
			print->width = -print->width;
		}
		i++;
	}
	return (i);
}

static void		proccessbefore(const char *f, t_printf *print, va_list list)
{
	int i;

	i = 0;
	print->direction = LEFT;
	if (f[i] == '-')
	{
		i += skip(f, '-');
		print->direction = RIGHT;
	}
	else if (f[i] == '0')
	{
		i += skip(f, '0');
		print->zero = 1;
	}
	i += handlewidth(f + i, print, list);
	print->skip += i;
}

void			proccessflags(const char *f, t_printf *print, va_list list)
{
	int i;

	i = 0;
	print->direction = LEFT;
	proccessbefore(f, print, list);
	i += print->skip;
	if (f[i] == '.')
	{
		print->dot = 1;
		if (ft_isdigit(f[++i]))
		{
			print->precision = ft_atoi(f + i);
			while (ft_isdigit(f[i]))
				i++;
		}
		else if (f[i] == '*')
		{
			print->precision = va_arg(list, int);
			i++;
		}
	}
	while (ft_strchr(FALGS, f[i]) || ft_isdigit(f[i]))
		i++;
	print->skip = i;
}
