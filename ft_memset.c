/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:48:28 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/11/07 15:39:42 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*a;

	a = b;
	i = 0;
	while (len--)
	{
		a[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
