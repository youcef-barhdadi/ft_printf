/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:21:16 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/11/07 15:34:48 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrchr(const char *s, int n)
{
	char *last;

	last = NULL;
	if (*s == '\0' && n == '\0')
		return ((char *)s);
	if (*s == '\0' || !s)
		return (NULL);
	while (*s)
	{
		if (*s == n)
			last = (char *)s;
		s++;
	}
	if ((char)n == '\0')
		return (char *)s;
	else
		return (last);
}
