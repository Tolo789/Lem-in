/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:27:16 by cmutti            #+#    #+#             */
/*   Updated: 2016/02/18 16:27:20 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_fill(char *str, t_print *print)
{
	int		i;
	int		tot;

	i = 0;
	tot = print->prec - (int)ft_strlen(print->value);
	if (print->value[0] == '-')
		tot++;
	while (i < tot)
		str[i++] = '0';
}

static int	ft_hash_count(t_print *print)
{
	if (print->type == 'O' || print->type == 'o')
	{
		if (print->value[0] == '0')
			return (0);
		return (1);
	}
	if ((print->type == 'x' || print->type == 'X') && print->value[0])
		return (2);
	return (0);
}

static int	ft_hash_apply(char *str, t_print *print)
{
	if (print->type == 'O' || print->type == 'o')
	{
		str[0] = '0';
		print->prec -= 1;
		return (1);
	}
	if ((print->type == 'x' || print->type == 'X') && print->value[0])
	{
		str[0] = '0';
		str[1] = 'x';
		print->prec -= (print->dot) ? 0 : 2;
		return (2);
	}
	return (0);
}

static int	ft_get_needed_len(t_print *print)
{
	int		i;

	i = 0;
	i = ft_strlen(print->value);
	(print->value[0] == '-') ? i-- : 0;
	(print->type == '%' && print->flag & 4) ? print->flag -= 4 : 0;
	(print->prec > i) ? i = print->prec : 0;
	(print->value[0] == '-' || print->flag & 2 || print->flag & 4) ? i++ : 0;
	if (print->flag & 8 && print->value[0] != '0')
		i += ft_hash_count(print);
	return (i);
}

char		*ft_apply_options(t_print *print)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = ft_strnew(ft_get_needed_len(print))))
		return (NULL);
	if (print->value[0] != '-' && (print->flag & 2 || print->flag & 4))
		str[i++] = (print->flag & 2) ? '+' : ' ';
	else if (print->value[0] == '-')
		str[i++] = '-';
	if (print->flag & 8 && print->value[0] != '0')
		i += ft_hash_apply(str, print);
	if (ft_check(print))
	{
		if (print->prec > (int)ft_strlen(print->value))
			ft_fill(&str[i], print);
		else if (print->prec == (int)ft_strlen(print->value) && print->value[0])
			ft_fill(&str[i], print);
	}
	if (print->value[0] == '-')
		ft_strcat(&str[i], &print->value[1]);
	else
		ft_strcat(&str[i], print->value);
	(print->flag & 16 && print->dot) ? print->flag -= 16 : 0;
	return (str);
}
