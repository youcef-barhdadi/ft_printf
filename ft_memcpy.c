/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:54:59 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/11/07 15:40:11 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void *ret;

	ret = dst;
	if (!((unsigned char*)dst) && !((unsigned char*)src))
		return (dst);
	if (!ft_memcmp(dst, src, n))
		return (dst);
	while (n--)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		dst++;
		src++;
	}
	return (ret);
}
