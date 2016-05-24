/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <cmutti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 15:50:57 by cmutti            #+#    #+#             */
/*   Updated: 2016/02/05 11:47:23 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_free_print(t_print *print)
{
	if (print)
	{
		if (print->value)
			free(print->value);
		if (print->len)
			free(print->len);
		free(print);
		print = NULL;
	}
	return (-1);
}

static int	ft_get_type(const char *str, size_t *i, t_print *print)
{
	if (str[*i] == 's' || str[*i] == 'S')
		print->type = str[*i];
	else if (str[*i] == 'd' || str[*i] == 'D' || str[*i] == 'i')
		print->type = str[*i];
	else if (str[*i] == 'o' || str[*i] == 'O')
		print->type = str[*i];
	else if (str[*i] == 'U' || str[*i] == 'u')
		print->type = str[*i];
	else if (str[*i] == 'x' || str[*i] == 'X')
		print->type = str[*i];
	else if (str[*i] == 'e' || str[*i] == 'E')
		print->type = str[*i];
	else if (str[*i] == 'f' || str[*i] == 'F')
		print->type = str[*i];
	else if (str[*i] == 'g' || str[*i] == 'G')
		print->type = str[*i];
	else if (str[*i] == 'a' || str[*i] == 'A')
		print->type = str[*i];
	else if (str[*i] == 'c' || str[*i] == 'C' || str[*i] == '%')
		print->type = str[*i];
	else if (str[*i] == 'p' || str[*i] == 'n')
		print->type = str[*i];
	else
		return (-1);
	return (1);
}

int			ft_get_var(char **str, int ret, va_list ap)
{
	t_print	*print;
	size_t	i;

	i = 0;
	if (!(print = (t_print*)ft_memalloc(sizeof(*print))))
		return (-1);
	if ((print->flag = ft_get_flag(*str, &i)) < 0)
		return (ft_free_print(print));
	if ((print->width = ft_get_width(*str, &i, print, ap)) < 0)
		return (ft_free_print(print));
	if ((print->prec = ft_get_prec(*str, &i, print, ap)) < 0)
		return (ft_free_print(print));
	if (!(print->len = ft_get_len(*str, &i)))
		return (ft_free_print(print));
	if (ft_get_type(*str, &i, print) < 0)
		return (ft_free_print(print));
	if (!(print->value = ft_get_value(print, ap, ret)))
		return (ft_free_print(print));
	str[0] += i + 1;
	return (ft_create_str(print, print->flag, print->dot));
}
