/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 18:39:32 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/11/07 15:38:57 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*fill_with(int size, char c)
{
	int		i;
	char	*new;

	i = 0;
	if (size < 0)
		size = 0;
	new = malloc(sizeof(char) * size + 1);
	if (!new)
		return (NULL);
	while (size--)
		new[i++] = c;
	new[i] = '\0';
	return (new);
}

static void		assign(char *str, char *zero)
{
	zero[0] = '0';
	str[0] = '-';
}

static char		*fix_precision(char *str, t_printf *print)
{
	int		len;
	char	*zero;
	char	*ret;

	len = 0;
	if (ft_atoi(str) == 0 && print->dot == 1 && print->precision == 0)
		return (ft_strdup(""));
	len = ft_strchr(str, '-') ? ft_strlen(str + 1) : ft_strlen(str);
	if (ft_strchr(str, '-') && len < print->precision)
	{
		zero = fill_with(print->precision - len, '0');
		assign(zero, str);
		ret = ft_strjoin(zero, str);
		free(zero);
		return (ret);
	}
	else if (len < print->precision)
	{
		zero = fill_with(print->precision - len	, '0');
		ret = ft_strjoin(zero, str);
		free(zero);
		return (ret);
	}
	return (ft_strdup(str));
}

static char		*fix_minwidth(char *str, t_printf *print, int zero)
{
	int		len;
	char	*width;
	char	*ret;
	char	chartorint;

	len = 0;
	chartorint = print->zero && !print->precision ? '0' : ' ';
	if (print->direction == LEFT && print->width > (int)ft_strlen(str))
	{
		width = fill_with(print->width - ft_strlen(str), chartorint);
		if (ft_strchr(str, '-') && zero)
			assign(width, str);
		ret = ft_strjoin(width, str);
		return (ret);
	}
	else if (print->width > (int)ft_strlen(str))
		if (print->width > (int)ft_strlen(str))
		{
			width = fill_with(print->width - (int)ft_strlen(str), ' ');
			ret = print->direction == LEFT ?
				ft_strjoin(width, str) : ft_strjoin(str, width);
			return (ret);
		}
	return (ft_strdup(str));
}

void			print_int(t_printf *print, va_list list)
{
	long	nbr;
	int		len;
	char	*str;
	char	*precision;
	char	*width;

	nbr = va_arg(list, int);
	str = ft_itoa(nbr);
	len = ft_strlen(str);
	precision = fix_precision(str, print);
	free(str);
	width = fix_minwidth(precision, print, print->zero);
	print->count += ft_strlen(width);
	ft_putstr_fd(width, 1);
}
