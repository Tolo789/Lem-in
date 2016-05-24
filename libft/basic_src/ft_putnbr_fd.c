/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:35:23 by cmutti            #+#    #+#             */
/*   Updated: 2015/11/24 11:35:28 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n < 10 && n > -10)
		ft_putchar_fd('0' + ft_abs(n), fd);
	else
	{
		ft_putnbr_fd(ft_abs(n / 10), fd);
		ft_putchar_fd('0' + ft_abs(n % 10), fd);
	}
}
