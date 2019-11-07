/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarhdad <ybarhdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:51:00 by ybarhdad          #+#    #+#             */
/*   Updated: 2019/11/07 15:33:27 by ybarhdad         ###   ########.fr       */
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

static	int		ft_nbrlen(unsigned long long nbr)
{
	unsigned long long	nnbr;
	int					len;

	nnbr = nbr;
	len = 0;
	if (nnbr == 0)
		return (1);
	while (nnbr)
	{
		nnbr = nnbr / 10;
		len++;
	}
	return (len);
}

static	void	fill(char *str, unsigned long long nnbr)
{
	int			i;
	int			sign;

	sign = 0;
	i = 0;
	if (nnbr == 0)
		str[i++] = '0';
	while (nnbr)
	{
		str[i++] = (nnbr % 10) + '0';
		nnbr = nnbr / 10;
	}
	str[i] = '\0';
	ft_reverse(str + sign);
}

char			*ft_ulltoa(unsigned long long nbr)
{
	unsigned long long	nnbr;
	char				*str;

	nnbr = nbr;
	str = (char *)malloc((sizeof(char) * ft_nbrlen(nnbr)) + 1);
	if (!str)
		return (NULL);
	fill(str, nnbr);
	return (str);
}
