/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 11:45:42 by cmutti            #+#    #+#             */
/*   Updated: 2016/02/19 11:45:45 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_str(wchar_t wc)
{
	size_t	j;
	size_t	size;
	wchar_t wchar;

	size = 0;
	j = 0;
	wchar = wc;
	while (wchar > 0)
	{
		wchar /= 2;
		j++;
	}
	if (j <= 11)
		size += (j <= 7) ? 1 : 2;
	else
		size += (j <= 16) ? 3 : 4;
	return (ft_strnew(size));
}

char		*ft_wctoa(wchar_t wchar)
{
	char	*str;
	int		j;
	size_t	index;
	wchar_t wc;

	index = 0;
	j = 0;
	if (!(str = ft_get_str(wchar)))
		return (NULL);
	if (wchar)
	{
		wc = wchar;
		while (wc > 0 && ++j)
			wc /= 2;
		if (j <= 7)
			ft_mask1(str, index, wchar);
		else if (j <= 11)
			ft_mask2(str, index, wchar);
		else if (j <= 16)
			ft_mask3(str, index, wchar);
		else
			ft_mask4(str, index, wchar);
	}
	return (str);
}
