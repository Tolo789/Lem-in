/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 12:47:10 by cmutti            #+#    #+#             */
/*   Updated: 2016/02/20 12:47:13 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_str(wchar_t *wstr)
{
	size_t	i;
	size_t	j;
	size_t	size;
	wchar_t wchar;

	i = 0;
	size = 0;
	if (!wstr)
		return (ft_strdup("(null)"));
	while (wstr[i])
	{
		j = 0;
		wchar = wstr[i];
		while (wchar > 0)
		{
			wchar /= 2;
			j++;
		}
		if (j <= 11)
			size += (j <= 7) ? 1 : 2;
		else
			size += (j <= 16) ? 3 : 4;
		i++;
	}
	return (ft_strnew(size));
}

char		*ft_wstoa(wchar_t *wstr)
{
	char	*str;
	size_t	i;
	int		j;
	size_t	index;
	wchar_t wchar;

	i = -1;
	index = 0;
	if (!(str = ft_get_str(wstr)))
		return (NULL);
	while (wstr && wstr[++i] && !(j = 0))
	{
		wchar = wstr[i];
		while (wchar > 0 && ++j)
			wchar /= 2;
		if (j <= 7)
			index += ft_mask1(str, index, wstr[i]);
		else if (j <= 11)
			index += ft_mask2(str, index, wstr[i]);
		else if (j <= 16)
			index += ft_mask3(str, index, wstr[i]);
		else
			index += ft_mask4(str, index, wstr[i]);
	}
	return (str);
}
