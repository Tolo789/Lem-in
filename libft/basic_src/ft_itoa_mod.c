/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 17:23:06 by cmutti            #+#    #+#             */
/*   Updated: 2016/01/09 17:23:07 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_ltoa(long nbr)
{
	long				nb;
	int					i;
	char				*str;

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
		str[i--] = '0' - nbr % 10;
		nbr /= -10;
	}
	while (str[i] != '-' && i >= 0)
	{
		str[i--] = '0' + nbr % 10;
		nbr /= 10;
	}
	return (str);
}

char	*ft_lltoa(long long nbr)
{
	long long			nb;
	int					i;
	char				*str;

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
		str[i--] = '0' - nbr % 10;
		nbr /= -10;
	}
	while (str[i] != '-' && i >= 0)
	{
		str[i--] = '0' + nbr % 10;
		nbr /= 10;
	}
	return (str);
}

char	*ft_uitoa(unsigned int nbr)
{
	unsigned int		nb;
	int					i;
	char				*str;

	nb = nbr;
	i = 0;
	while (nb > 9 && ++i)
	{
		nb /= 10;
	}
	str = ft_strnew(i + 1);
	if (!str)
		return (NULL);
	while (i >= 0)
	{
		str[i--] = '0' + nbr % 10;
		nbr /= 10;
	}
	return (str);
}

char	*ft_ultoa(unsigned long nbr)
{
	unsigned long		nb;
	int					i;
	char				*str;

	nb = nbr;
	i = 0;
	while (nb > 9 && ++i)
	{
		nb /= 10;
	}
	str = ft_strnew(i + 1);
	if (!str)
		return (NULL);
	while (i >= 0)
	{
		str[i--] = '0' + nbr % 10;
		nbr /= 10;
	}
	return (str);
}

char	*ft_ulltoa(unsigned long long nbr)
{
	unsigned long long	nb;
	int					i;
	char				*str;

	nb = nbr;
	i = 0;
	while (nb > 9 && ++i)
	{
		nb /= 10;
	}
	str = ft_strnew(i + 1);
	if (!str)
		return (NULL);
	while (i >= 0)
	{
		str[i--] = '0' + nbr % 10;
		nbr /= 10;
	}
	return (str);
}
