/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 18:41:22 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/11/07 15:37:24 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*fill_with(int size, char c)
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

void			print_string(char *str, t_printf *print)
{
	int		len;
	char	*width;

	if (!str)
		str = ft_strdup("(null)");
	if (print->precision == 0 && print->dot)
		str = "";
	len = ft_strlen(str);
	if (print->precision > 0 && print->precision < len)
	{
		len = print->precision;
		str = ft_substr(str, 0, len);
	}
	width = fill_with(print->width-- - len, ' ');
	if (print->direction == LEFT)
		str = ft_strjoin(width, str);
	else
		str = ft_strjoin(str, width);
	ft_putstr_fd(str, 1);
	print->count += ft_strlen(str);
}
