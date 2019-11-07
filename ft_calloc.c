/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:56:27 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/11/07 15:32:24 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *new;

	new = NULL;
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	new = malloc(count * size);
	if (!new)
		return (NULL);
	ft_memset(new, 0, count * size);
	return (new);
}
