/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_mod2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 19:27:42 by cmutti            #+#    #+#             */
/*   Updated: 2016/01/09 19:27:43 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_imtoa(intmax_t nbr)
{
	intmax_t			nb;
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

char	*ft_uimtoa(uintmax_t nbr)
{
	uintmax_t			nb;
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

char	*ft_ssttoa(ssize_t nbr)
{
	ssize_t				nb;
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

char	*ft_sttoa(size_t nbr)
{
	size_t				nb;
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

char	*ft_ustoa(unsigned short nbr)
{
	unsigned short		nb;
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
