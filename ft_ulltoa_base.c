/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:22:31 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/11/07 15:33:31 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static	void	ft_reverse(char *str)
{
	int		len;
	int		i;

	len = ft_strlen(str) - 1;
	i = 0;
	while (i < len)
	{
		ft_swap(&str[i], &str[len]);
		i++;
		len--;
	}
}

static	int		ft_nbrlen(size_t nbr, int base)
{
	size_t	nnbr;
	int		len;

	nnbr = nbr;
	len = 0;
	if (nnbr == 0)
		return (1);
	while (nnbr)
	{
		nnbr = nnbr / base;
		len++;
	}
	return (len);
}

static	void	fill(char *str, size_t nbr, char *base)
{
	int		i;
	int		size;

	size = ft_strlen(base);
	i = 0;
	if (nbr == 0)
	{
		str[i++] = base[0];
	}
	while (nbr)
	{
		str[i++] = base[nbr % size];
		nbr = nbr / size;
	}
	str[i] = '\0';
	ft_reverse(str);
}

char			*ft_ulltoa_base(size_t nbr, char *basechar)
{
	int			base;
	char		*str;

	base = ft_strlen(basechar);
	str = (char *)malloc(sizeof(char) * ft_nbrlen(nbr, base) + 1);
	if (!str)
		return (NULL);
	fill(str, nbr, basechar);
	return (str);
}
