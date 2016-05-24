/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <cmutti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 11:52:51 by cmutti            #+#    #+#             */
/*   Updated: 2016/02/08 15:07:40 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_flag(const char *s, size_t *index)
{
	int		j;
	size_t	i;

	j = 0;
	i = *index;
	while (s[i] == 45 || s[i] == 43 || s[i] == 32 || s[i] == 35 || s[i] == '0')
	{
		if (s[i] == '-' && !(j & 1))
			j += 1;
		if (s[i] == '+' && !(j & 2))
			j += 2;
		if (s[i] == ' ' && !(j & 4))
			j += 4;
		if (s[i] == '#' && !(j & 8))
			j += 8;
		if (s[i] == '0' && !(j & 16))
			j += 16;
		i++;
	}
	*index = i;
	return (j);
}

int		ft_get_width(const char *s, size_t *index, t_print *print, va_list ap)
{
	int		i;
	char	*str;

	i = *index;
	if (s[i] == '*' && ++(index[0]))
	{
		if ((i = va_arg(ap, int)) < 0)
		{
			print->flag += (print->flag & 1) ? 0 : 1;
			i = -i;
		}
		return (i);
	}
	while (ft_isdigit(s[i]))
		i++;
	if (i == (int)*index)
		return (0);
	str = ft_strsub(s, (unsigned int)*index, i - *index);
	if (!str)
		return (-1);
	*index = i;
	i = ft_atoi(str);
	free(str);
	return ((i < 0) ? 0 : i);
}

int		ft_get_prec(const char *s, size_t *index, t_print *print, va_list ap)
{
	int		i;
	char	*str;

	i = 0;
	print->dot = 0;
	if (s[*index] == '.' && ++(print->dot))
	{
		*index += 1;
		if (s[*index] == '*' && ++index[0])
			return (((i = va_arg(ap, int)) >= 0) ? i : ++(print->dot));
		while (ft_isdigit(s[*index + i]))
			i++;
		if (i == 0 && (print->dot = 3))
			return (i);
		str = ft_strsub(s, (unsigned int)*index, i);
		if (!str)
			return (-1);
		*index += i;
		i = ft_atoi(str);
		free(str);
	}
	return ((i < 0) ? 0 : i);
}

char	*ft_get_len(const char *s, size_t *index)
{
	size_t	i;

	i = *index;
	if (s[i] == 'h' && s[i + 1] == 'h')
	{
		*index += 2;
		return (ft_strdup("hh"));
	}
	if (s[i] == 'l' && s[i + 1] == 'l')
	{
		*index += 2;
		return (ft_strdup("ll"));
	}
	if (s[i] == 'h' || s[i] == 'l' || s[i] == 'j' || s[i] == 'z')
	{
		*index += 1;
		return (ft_ctoa(s[i]));
	}
	return (ft_strnew(0));
}
