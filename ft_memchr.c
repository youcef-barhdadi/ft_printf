/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:59:25 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/11/07 15:40:11 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*a;

	a = (unsigned char *)s;
	i = 0;
	while (n-- > 0)
	{
		if (a[i] == (unsigned char)c)
			return (&a[i]);
		i++;
	}
	return (0);
}
