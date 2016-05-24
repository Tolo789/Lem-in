/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_mod.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <cmutti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 17:58:14 by cmutti            #+#    #+#             */
/*   Updated: 2016/02/04 15:44:40 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_ltoa_base(long nbr, int base)
{
	unsigned long		nb;
	char				*str;
	char				*conv;
	int					i;

	i = (nbr > 0) ? 0 : 1;
	nb = nbr;
	conv = "0123456789abcdefg";
	if (base == 10)
		return (ft_ltoa(nbr));
	while (nb > 0)
	{
		nb /= base;
		i++;
	}
	str = ft_strnew(i + 1);
	if (!str)
		return (NULL);
	i--;
	while (i >= 0)
	{
		str[i--] = conv[nbr % base];
		nbr /= base;
	}
	return (str);
}

char	*ft_sttoa_base(size_t nbr, int base)
{
	size_t				nb;
	char				*str;
	char				*conv;
	int					i;

	i = (nbr > 0) ? 0 : 1;
	nb = nbr;
	conv = "0123456789abcdefg";
	while (nb > 0)
	{
		nb /= base;
		i++;
	}
	str = ft_strnew(i + 1);
	if (!str)
		return (NULL);
	i--;
	while (i >= 0)
	{
		str[i--] = conv[nbr % base];
		nbr /= base;
	}
	return (str);
}

char	*ft_uimtoa_base(uintmax_t nbr, int base)
{
	uintmax_t			nb;
	char				*str;
	char				*conv;
	int					i;

	i = (nbr > 0) ? 0 : 1;
	nb = nbr;
	conv = "0123456789abcdefg";
	while (nb > 0)
	{
		nb /= base;
		i++;
	}
	str = ft_strnew(i + 1);
	if (!str)
		return (NULL);
	i--;
	while (i >= 0)
	{
		str[i--] = conv[nbr % base];
		nbr /= base;
	}
	return (str);
}

char	*ft_uctoa_base(unsigned char nbr, int base)
{
	unsigned char		nb;
	char				*str;
	char				*conv;
	int					i;

	i = (nbr > 0) ? 0 : 1;
	nb = nbr;
	conv = "0123456789abcdefg";
	while (nb > 0)
	{
		nb /= base;
		i++;
	}
	str = ft_strnew(i + 1);
	if (!str)
		return (NULL);
	i--;
	while (i >= 0)
	{
		str[i--] = conv[nbr % base];
		nbr /= base;
	}
	return (str);
}
