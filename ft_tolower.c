/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:40:36 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/11/07 15:33:41 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_tolower(int c)
{
	if (ft_isupper(c))
	{
		return (((unsigned char)c) + 32);
	}
	return (c);
}