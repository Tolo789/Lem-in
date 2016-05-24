/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len_modif.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <cmutti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:23:55 by cmutti            #+#    #+#             */
/*   Updated: 2016/02/05 11:39:09 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_len_modif4(t_print *prnt, va_list ap)
{
	char	c;

	c = prnt->len[0];
	if (c == 'h' && prnt->type == 'D')
		return (ft_uitoa(va_arg(ap, int)));
	if (c == 'h' && (prnt->type == 'd' || prnt->type == 'i'))
		return (ft_itoa(va_arg(ap, int)));
	if (c == 'h' && (prnt->type == 'o'))
		return (ft_ustoa_base((unsigned short)(va_arg(ap, int)), 8));
	if (c == 'h' && (prnt->type == 'O'))
		return (ft_uitoa_base((unsigned int)(va_arg(ap, int)), 8));
	if (c == 'h' && (prnt->type == 'u' || prnt->type == 'U'))
		return (ft_ustoa((unsigned short)(va_arg(ap, long int))));
	if (c == 'h' && (prnt->type == 'x' || prnt->type == 'X'))
		return (ft_ustoa_base((unsigned short)(va_arg(ap, int)), 16));
	return (NULL);
}

char		*ft_get_len_modif3(t_print *prnt, va_list ap)
{
	char	c;

	c = prnt->len[0];
	if (c == 'j' && (prnt->type == 'D'))
		return (ft_imtoa(va_arg(ap, intmax_t)));
	if (c == 'j' && (prnt->type == 'd' || prnt->type == 'i'))
		return (ft_imtoa(va_arg(ap, intmax_t)));
	if (c == 'j' && (prnt->type == 'o' || prnt->type == 'O'))
		return (ft_uimtoa_base(va_arg(ap, uintmax_t), 8));
	if (c == 'j' && (prnt->type == 'u' || prnt->type == 'U'))
		return (ft_uimtoa(va_arg(ap, uintmax_t)));
	if (c == 'j' && (prnt->type == 'x' || prnt->type == 'X'))
		return (ft_uimtoa_base(va_arg(ap, uintmax_t), 16));
	if (c == 'z' && (prnt->type == 'D'))
		return (ft_sttoa(va_arg(ap, size_t)));
	if (c == 'z' && (prnt->type == 'd' || prnt->type == 'i'))
		return (ft_lltoa(va_arg(ap, size_t)));
	if (c == 'z' && (prnt->type == 'o' || prnt->type == 'O'))
		return (ft_sttoa_base(va_arg(ap, size_t), 8));
	if (c == 'z' && (prnt->type == 'u' || prnt->type == 'U'))
		return (ft_sttoa(va_arg(ap, size_t)));
	if (c == 'z' && (prnt->type == 'x' || prnt->type == 'X'))
		return (ft_sttoa_base(va_arg(ap, size_t), 16));
	return (ft_get_len_modif4(prnt, ap));
}

char		*ft_get_len_modif2(t_print *prnt, va_list ap)
{
	if (prnt->type == 'd' || prnt->type == 'i')
		return (ft_ltoa(va_arg(ap, long)));
	if (prnt->type == 'o' || prnt->type == 'O')
		return (ft_ultoa_base(va_arg(ap, unsigned long), 8));
	if (prnt->type == 'u' || prnt->type == 'U')
		return (ft_ultoa(va_arg(ap, unsigned long)));
	if (prnt->type == 'x' || prnt->type == 'X')
		return (ft_ultoa_base(va_arg(ap, unsigned long), 16));
	if (prnt->type == 'c')
		return (ft_wctoa(va_arg(ap, wchar_t)));
	if (prnt->type == 's')
		return (ft_wstoa(va_arg(ap, wchar_t *)));
	if (prnt->type == 'D')
		return (ft_ltoa(va_arg(ap, long int)));
	return (NULL);
}

char		*ft_get_len_modif(t_print *prnt, va_list ap)
{
	if (ft_strstr(prnt->len, "hh") && prnt->type == 'D')
		return (ft_uitoa((char)(va_arg(ap, int))));
	if (ft_strstr(prnt->len, "hh") && (prnt->type == 'd' || prnt->type == 'i'))
		return (ft_itoa((char)(va_arg(ap, int))));
	if (ft_strstr(prnt->len, "hh") && (prnt->type == 'o' || prnt->type == 'O'))
		return (ft_uctoa_base((unsigned char)(va_arg(ap, int)), 8));
	if (ft_strstr(prnt->len, "hh") && (prnt->type == 'u' || prnt->type == 'U'))
		return (ft_uctoa((unsigned char)(va_arg(ap, int))));
	if (ft_strstr(prnt->len, "hh") && (prnt->type == 'x' || prnt->type == 'X'))
		return (ft_uctoa_base((unsigned char)(va_arg(ap, int)), 16));
	if (ft_strstr(prnt->len, "ll") && prnt->type == 'D')
		return (ft_lltoa(va_arg(ap, long long)));
	if (ft_strstr(prnt->len, "ll") && (prnt->type == 'd' || prnt->type == 'i'))
		return (ft_lltoa(va_arg(ap, long long)));
	if (ft_strstr(prnt->len, "ll") && (prnt->type == 'o' || prnt->type == 'O'))
		return (ft_ulltoa_base(va_arg(ap, unsigned long long), 8));
	if (ft_strstr(prnt->len, "ll") && (prnt->type == 'u' || prnt->type == 'U'))
		return (ft_ulltoa(va_arg(ap, unsigned long long)));
	if (ft_strstr(prnt->len, "ll") && (prnt->type == 'x' || prnt->type == 'X'))
		return (ft_ulltoa_base(va_arg(ap, unsigned long long), 16));
	return (NULL);
}
