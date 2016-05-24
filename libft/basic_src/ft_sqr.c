/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 14:16:51 by cmutti            #+#    #+#             */
/*   Updated: 2016/05/10 14:16:56 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_sqr(int nbr)
{
	int				i;

	i = 0;
	if (nbr <= 0)
		return (0);
	while (i * i < nbr)
		i++;
	if (i * i == nbr)
		return (i);
	i -= (i * i - nbr < nbr - (i - 1) * (i - 1)) ? 0 : 1;
	return (i);
}

unsigned int	ft_uisqr(unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	if (nbr <= 0)
		return (0);
	while (i * i < nbr)
		i++;
	if (i * i == nbr)
		return (i);
	i -= (i * i - nbr < nbr - (i - 1) * (i - 1)) ? 0 : 1;
	return (i);
}
