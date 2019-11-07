/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 22:36:45 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/11/07 15:34:48 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size;
	char	*new;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	new = (char *)malloc(sizeof(char) * size + 1);
	if (!new)
		return (NULL);
	while (i < size)
	{
		new[i] = (f)(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
