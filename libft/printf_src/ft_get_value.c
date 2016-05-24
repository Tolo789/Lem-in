/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <cmutti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 16:55:57 by cmutti            #+#    #+#             */
/*   Updated: 2016/02/04 18:35:15 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_add_adress(char *str)
{
	char	*tmp;

	if (!str)
		return (NULL);
	tmp = ft_strnew(ft_strlen(str) + 2);
	if (!tmp)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	tmp[0] = '0';
	tmp[1] = 'x';
	ft_strcat(tmp, str);
	free(str);
	str = NULL;
	return (tmp);
}

static char	*ft_get_value2(char c, va_list ap)
{
	if (c == '%' || c == 'c')
		return (c == '%' ? ft_ctoa('%') : ft_ctoa(va_arg(ap, int)));
	if (c == 'C')
		return (ft_wctoa(va_arg(ap, wchar_t)));
	if (c == 'S')
		return (ft_wstoa(va_arg(ap, wchar_t *)));
	if (c == 'p')
		return (ft_add_adress(ft_ltoa_base(va_arg(ap, long), 16)));
	return (NULL);
}

char		*ft_get_value(t_print *print, va_list ap, int ret)
{
	if (print->type == 'n')
		return (ft_saveret(print, ap, ret));
	if (print->len[0] && print->len[1])
		return (ft_get_len_modif(print, ap));
	if (print->len[0] == 'l')
		return (ft_get_len_modif2(print, ap));
	if (print->len[0])
		return (ft_get_len_modif3(print, ap));
	if (print->type == 's')
		return (ft_strdup(va_arg(ap, char *)));
	if (print->type == 'd' || print->type == 'i')
		return (ft_itoa(va_arg(ap, int)));
	if (print->type == 'D')
		return (ft_ltoa(va_arg(ap, long int)));
	if (print->type == 'o')
		return (ft_uitoa_base(va_arg(ap, unsigned int), 8));
	if (print->type == 'O')
		return (ft_ultoa_base(va_arg(ap, unsigned long), 8));
	if (print->type == 'u')
		return (ft_uitoa(va_arg(ap, unsigned int)));
	if (print->type == 'U')
		return (ft_ultoa(va_arg(ap, unsigned long int)));
	if (print->type == 'x' || print->type == 'X')
		return (ft_uitoa_base(va_arg(ap, unsigned int), 16));
	return (ft_get_value2(print->type, ap));
}
