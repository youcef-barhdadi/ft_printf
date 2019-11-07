/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:25:27 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/11/07 15:40:10 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *d;
	unsigned char *s;
	unsigned char cc;

	if (!dst && !src)
		return (NULL);
	d = dst;
	s = (unsigned char *)src;
	cc = (unsigned char)c;
	while (n--)
	{
		*(d++) = *(s);
		if (*s++ == cc)
			return (d);
	}
	return (0);
}
