/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <cmutti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 11:15:36 by cmutti            #+#    #+#             */
/*   Updated: 2016/02/08 14:48:26 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int			ft_check(t_print *print)
{
	if (print->type == 's' || print->type == 'S' || print->type == 'c')
		return (0);
	if (print->type == 'p' || print->type == 'n' || print->type == 'C')
		return (0);
	return (1);
}

static int	ft_print_var(t_print *print, char *str)
{
	int		size;
	int		i;
	char	c;

	i = 0;
	size = (print->type == 'c' && !str[0]) ? 1 : ft_strlen(str);
	size = (print->type == 'C' && !str[0]) ? 1 : size;
	if (print->type == 's' && print->dot == 2)
		print->dot = 0;
	if (print->type == 's' && print->dot && print->prec < size)
		size = print->prec;
	if (print->type == 'S' && print->dot && print->prec < size)
		size = print->prec;
	c = (print->flag & 16) ? '0' : ' ';
	if (print->flag & 1)
		write(1, str, size);
	while (size + i < print->width)
	{
		write(1, &c, 1);
		i++;
	}
	if (!(print->flag & 1))
		write(1, str, size);
	return (size + i);
}

int			ft_create_str(t_print *print, int flag, int dot)
{
	char	*str;
	int		size;

	size = 0;
	(flag & 16 && flag & 1 && print->type == '%') ? print->flag -= 16 : 0;
	if (print->type == 'n' && ft_free_print(print) < 0)
		return (0);
	if (print->type == '%' && print->dot && !(print->dot = 0))
		print->prec = 0;
	if (!print->dot && print->flag & 16)
	{
		print->prec = print->width;
		if (print->value[0] == '-' || print->flag & 2 || print->flag & 4)
			print->prec--;
	}
	if (dot && !print->prec && print->value[0] == '0' && ft_check(print))
		print->value[0] = 0;
	if (!(str = ft_apply_options(print)))
		return (-1);
	(print->type == 'X') ? ft_upstr(&str) : 0;
	size = ft_print_var(print, str);
	free(str);
	str = NULL;
	ft_free_print(print);
	return (size);
}
