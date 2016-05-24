/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 11:40:18 by cmutti            #+#    #+#             */
/*   Updated: 2016/01/02 11:40:18 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_itoa(int nbr)
{
	int		nb;
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
