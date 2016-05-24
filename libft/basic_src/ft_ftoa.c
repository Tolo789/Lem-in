/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 13:40:56 by cmutti            #+#    #+#             */
/*   Updated: 2016/01/02 13:41:06 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>
#include <stdio.h>

static char	*ft_join_free(char *str, char *sub)
{
	char	*newstr;

	if (!str || !sub)
	{
		if (str)
			ft_strdel(&str);
		if (sub)
			ft_strdel(&sub);
		return (NULL);
	}
	newstr = ft_strjoin(str, sub);
	if (!newstr)
		return (NULL);
	ft_strdel(&sub);
	ft_strdel(&str);
	return (newstr);
}

static char	*ft_first(double nbr)
{
	double	nb;
	int		i;
	char	*str;

	nb = nbr;
	i = (nbr >= 0) ? 0 : 1;
	while ((nb > 9 || nb < -9) && ++i)
	{
		nb /= 10;
	}
	str = ft_strnew(i + 1);
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		str[0] = '-';
		str[i--] = '0' - (long int)nbr % 10;
		nbr /= -10;
	}
	while (i >= 0 && str[i] != '-')
	{
		str[i--] = '0' + (long int)nbr % 10;
		nbr /= 10;
	}
	return (str);
}

static void	ft_fill_decimal(char *str, double nbr, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		j++;
		nbr = nbr * 10;
		str[j] = '0' + (long int)nbr % 10;
		nbr = nbr - (long int)nbr;
	}
}

static char	*ft_second(double nbr)
{
	int		i;
	char	*str;
	double	nb;

	i = 0;
	nb = nbr;
	while (nb > 0 && nb < 1)
	{
		i++;
		nb = nb * 10;
		nb = nb - (long int)nb;
	}
	if (!(str = (i > 6) ? ft_strnew(i + 1) : ft_strnew(7)))
		return (NULL);
	if (i > 6)
		str = (char*)ft_memset(str, '0', i + 1);
	else
		str = (char*)ft_memset(str, '0', 7);
	str[0] = '.';
	ft_fill_decimal(str, nbr, i);
	return (str);
}

char		*ft_ftoa(double nbr)
{
	char	*str;

	str = ft_first((double)((long int)nbr));
	nbr = nbr - (long int)nbr;
	if (nbr < 0)
		nbr *= -1;
	str = ft_join_free(str, ft_second(nbr));
	return (str);
}
