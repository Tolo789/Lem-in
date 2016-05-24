/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_masks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 12:47:19 by cmutti            #+#    #+#             */
/*   Updated: 2016/02/20 12:47:26 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_get_wc(wchar_t wchar)
{
	int		i;
	char	c;

	i = 0;
	c = -128;
	while (i < 6)
	{
		if (wchar % 2)
			c += ft_pow(2, i);
		i++;
		wchar /= 2;
	}
	return (c);
}

int			ft_mask1(char *str, int size, wchar_t wchar)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	while (wchar > 0)
	{
		if (wchar % 2)
			c += ft_pow(2, i);
		i++;
		wchar /= 2;
	}
	str[size] = c;
	return (1);
}

int			ft_mask2(char *str, int size, wchar_t wchar)
{
	int		i;
	char	c;

	i = 0;
	str[size + 1] = ft_get_wc(wchar);
	c = -64;
	wchar /= 64;
	while (wchar > 0)
	{
		if (wchar % 2)
			c += ft_pow(2, i);
		i++;
		wchar /= 2;
	}
	str[size] = c;
	return (2);
}

int			ft_mask3(char *str, int size, wchar_t wchar)
{
	int		i;
	char	c;

	i = 0;
	c = -32;
	str[size + 2] = ft_get_wc(wchar);
	wchar /= 64;
	str[size + 1] = ft_get_wc(wchar);
	wchar /= 64;
	while (wchar > 0)
	{
		if (wchar % 2)
			c += ft_pow(2, i);
		i++;
		wchar /= 2;
	}
	str[size] = c;
	return (3);
}

int			ft_mask4(char *str, int size, wchar_t wchar)
{
	int		i;
	char	c;

	i = 0;
	c = -16;
	str[size + 3] = ft_get_wc(wchar);
	wchar /= 64;
	str[size + 2] = ft_get_wc(wchar);
	wchar /= 64;
	str[size + 1] = ft_get_wc(wchar);
	wchar /= 64;
	while (wchar > 0)
	{
		if (wchar % 2)
			c += ft_pow(2, i);
		i++;
		wchar /= 2;
	}
	str[size] = c;
	return (4);
}
