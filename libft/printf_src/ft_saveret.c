/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_saveret.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <cmutti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 13:17:14 by cmutti            #+#    #+#             */
/*   Updated: 2016/02/04 18:23:18 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_saveret(t_print *print, va_list ap, int ret)
{
	char	*str;
	int		good;

	good = 0;
	if (!(str = ft_strnew(0)))
		return (NULL);
	if (!print->len[0] && ++good)
		*(va_arg(ap, int*)) = ret;
	else if (print->len[1] != 'l' && print->len[1] != 'l' && ++good)
		*(va_arg(ap, long long*)) = ret;
	else if (print->len[0] == 'l' && ++good)
		*(va_arg(ap, long*)) = ret;
	else if (print->len[1] != 'h' && print->len[1] != 'h' && ++good)
		*(va_arg(ap, signed char*)) = ret;
	else if (print->len[0] == 'h' && ++good)
		*(va_arg(ap, short*)) = ret;
	else if (print->len[0] == 'j' && ++good)
		*(va_arg(ap, intmax_t*)) = ret;
	else if (print->len[0] == 'z' && ++good)
		*(va_arg(ap, size_t*)) = ret;
	return ((good == 0) ? NULL : str);
}
