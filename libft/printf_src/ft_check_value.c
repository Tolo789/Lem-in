/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <cmutti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 19:08:20 by cmutti            #+#    #+#             */
/*   Updated: 2016/02/05 11:37:47 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_len_modif4(t_print *prnt)
{
	char	c;

	c = prnt->len[0];
	if (prnt->type == 'i')
		return (1);
	if (prnt->type == 'd' || prnt->type == 'D')
		return (1);
	if (prnt->type == 'o' || prnt->type == 'O')
		return (1);
	if (prnt->type == 'u' || prnt->type == 'U')
		return (1);
	if (prnt->type == 'x' || prnt->type == 'X')
		return (1);
	if (prnt->type == 'n')
		return (1);
	return (-1);
}

static int	ft_check_len_modif3(t_print *prnt)
{
	char	c;

	c = prnt->len[0];
	if (c == 'j' && (prnt->type == 'i' || prnt->type == 'n'))
		return (1);
	if (c == 'j' && (prnt->type == 'd' || prnt->type == 'D'))
		return (1);
	if (c == 'j' && (prnt->type == 'o' || prnt->type == 'O'))
		return (1);
	if (c == 'j' && (prnt->type == 'u' || prnt->type == 'U'))
		return (1);
	if (c == 'j' && (prnt->type == 'x' || prnt->type == 'X'))
		return (1);
	if (c == 'z' && (prnt->type == 'i' || prnt->type == 'n'))
		return (1);
	if (c == 'z' && (prnt->type == 'd' || prnt->type == 'D'))
		return (1);
	if (c == 'z' && (prnt->type == 'o' || prnt->type == 'O'))
		return (1);
	if (c == 'z' && (prnt->type == 'u' || prnt->type == 'U'))
		return (1);
	if (c == 'z' && (prnt->type == 'x' || prnt->type == 'X'))
		return (1);
	return (-1);
}

static int	ft_check_len_modif2(t_print *prnt)
{
	if (prnt->type == 'd' || prnt->type == 'i')
		return (1);
	if (prnt->type == 'o' || prnt->type == 'O')
		return (1);
	if (prnt->type == 'u' || prnt->type == 'U')
		return (1);
	if (prnt->type == 'x' || prnt->type == 'X')
		return (1);
	if (prnt->type == 'n' || prnt->type == 'D')
		return (1);
	if (prnt->type == 'c')
		return (1);
	if (prnt->type == 's')
		return (1);
	return (-1);
}

static int	ft_check_len_modif(t_print *prnt)
{
	if (ft_strstr(prnt->len, "hh") && (prnt->type == 'd' || prnt->type == 'D'))
		return (1);
	if (ft_strstr(prnt->len, "hh") && (prnt->type == 'o' || prnt->type == 'O'))
		return (1);
	if (ft_strstr(prnt->len, "hh") && (prnt->type == 'u' || prnt->type == 'U'))
		return (1);
	if (ft_strstr(prnt->len, "hh") && (prnt->type == 'x' || prnt->type == 'X'))
		return (1);
	if (ft_strstr(prnt->len, "hh") && (prnt->type == 'n' || prnt->type == 'i'))
		return (1);
	if (ft_strstr(prnt->len, "ll") && (prnt->type == 'd' || prnt->type == 'D'))
		return (1);
	if (ft_strstr(prnt->len, "ll") && (prnt->type == 'o' || prnt->type == 'O'))
		return (1);
	if (ft_strstr(prnt->len, "ll") && (prnt->type == 'u' || prnt->type == 'U'))
		return (1);
	if (ft_strstr(prnt->len, "ll") && (prnt->type == 'x' || prnt->type == 'X'))
		return (1);
	if (ft_strstr(prnt->len, "ll") && (prnt->type == 'n' || prnt->type == 'i'))
		return (1);
	return (-1);
}

int			ft_check_value(t_print *print)
{
	if (print->len[0] && print->len[1])
		return (ft_check_len_modif(print));
	if (print->len[0] == 'l')
		return (ft_check_len_modif2(print));
	if (print->len[0] == 'j' || print->len[0] == 'z')
		return (ft_check_len_modif3(print));
	if (print->len[0] == 'h')
		return (ft_check_len_modif4(print));
	return (1);
}
