/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 11:46:54 by cmutti            #+#    #+#             */
/*   Updated: 2016/02/19 11:46:57 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_width(const char *s, size_t *index)
{
	size_t	i;

	i = *index;
	if (s[i] == '*')
	{
		index[0]++;
		return (1);
	}
	while (ft_isdigit(s[i]))
		i++;
	if (i != *index)
	{
		*index = i;
		return (i);
	}
	return (0);
}

static int	ft_check_prec(const char *s, size_t *index, t_print *print)
{
	size_t	i;

	i = 0;
	print->dot = 0;
	if (s[*index] == '.' && ++(print->dot))
	{
		*index += 1;
		if (s[*index] == '*' && ++index[0])
			return (1);
		while (ft_isdigit(s[*index + i]))
			i++;
		if (i > 0)
			*index += i;
		else if ((print->dot = 3))
			return (i);
	}
	return (i);
}

static int	ft_check_type(const char *str, size_t *i, t_print *print)
{
	if (str[*i] == 's' || str[*i] == 'S')
		print->type = str[*i];
	else if (str[*i] == 'd' || str[*i] == 'D' || str[*i] == 'i')
		print->type = str[*i];
	else if (str[*i] == 'o' || str[*i] == 'O')
		print->type = str[*i];
	else if (str[*i] == 'u' || str[*i] == 'U')
		print->type = str[*i];
	else if (str[*i] == 'x' || str[*i] == 'X')
		print->type = str[*i];
	else if (str[*i] == 'c' || str[*i] == 'C' || str[*i] == '%')
		print->type = str[*i];
	else if (str[*i] == 'p' || str[*i] == 'n')
		print->type = str[*i];
	else
		return (-1);
	return (1);
}

static int	ft_is_compatible(int flag, char type, int dot)
{
	if (flag & 8 && (type == 'd' || type == 'D' || type == 'i' || type == 'b'))
		return (-1);
	if (flag & 8 && (type == 's' || type == 'p' || type == 'n' || type == 'S'))
		return (-1);
	if ((type == 'c') && (flag & 16 || flag & 2 || flag & 4 || flag & 8))
		return (-1);
	if (type == 'p' && (flag & 4 || flag & 2 || flag & 16))
		return (-1);
	if ((type == 'u' || type == 'U') && (flag & 4 || flag & 2 || flag & 8))
		return (-1);
	if ((type == 'x' || type == 'X') && (flag & 4 || flag & 2))
		return (-1);
	if (type == 'C' && (flag & 8 || flag & 4 || flag & 2 || flag & 16))
		return (-1);
	if ((type == 's' || type == 'S') && (flag & 16 || flag & 4 || flag & 2))
		return (-1);
	if ((type == 'o' || type == 'O' || type == 'b') && (flag & 2 || flag & 4))
		return (-1);
	(flag & 16 && flag & 1 && type == '%') ? flag -= 16 : 0;
	if (flag & 16 && flag & 1 && type != '%')
		return (-1);
	if ((type == 'S' || type == 'c' || type == 'p') && dot && dot != 3)
		return (-1);
	return ((flag & 2 && flag & 4) ? -1 : 1);
}

int			ft_check_var(char **str)
{
	size_t	i;
	t_print	*print;

	i = 0;
	str[0]++;
	if (!(print = (t_print*)ft_memalloc(sizeof(*print))))
		return (-1);
	print->value = NULL;
	if ((print->flag = ft_get_flag(*str, &i)) < 0)
		return (ft_free_print(print));
	if ((print->width = ft_check_width(*str, &i)) < 0)
		return (ft_free_print(print));
	if ((print->prec = ft_check_prec(*str, &i, print)) < 0)
		return (ft_free_print(print));
	if (!(print->len = ft_get_len(*str, &i)))
		return (ft_free_print(print));
	if (ft_check_type(*str, &i, print) < 0)
		return (ft_free_print(print));
	if (ft_check_value(print) < 0)
		return (ft_free_print(print));
	if (ft_is_compatible(print->flag, print->type, print->dot) < 0)
		return (ft_free_print(print));
	ft_free_print(print);
	*str += i + 1;
	return (1);
}
