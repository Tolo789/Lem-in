/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <cmutti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:54:47 by cmutti            #+#    #+#             */
/*   Updated: 2016/02/05 11:46:10 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putvar(char **str, int ret, va_list ap)
{
	str[0]++;
	if (**str == '%')
	{
		write(1, *str, 1);
		str[0]++;
		return (1);
	}
	return (ft_get_var(str, ret, ap));
}

static int	ft_putprintf(char *str, va_list ap)
{
	int		i;
	int		j;
	int		ret;

	i = 0;
	ret = 0;
	while (*str)
	{
		j = 0;
		while (str[j] && str[j] != '%')
			j++;
		if (j)
		{
			write(1, str, j);
			ret += j;
			str += j;
			j = 0;
		}
		if (*str == '%' && (j = ft_putvar(&str, ret, ap)) < 0)
			return (-1);
		else if (j)
			ret += j;
	}
	return (ret);
}

static int	ft_check_format(char *str)
{
	size_t	j;

	j = 0;
	while (*str)
	{
		j = 0;
		while (str[j] && str[j] != '%')
		{
			j++;
		}
		if (j)
			str += j;
		if (*str == '%' && ft_check_var(&str) < 0)
			return (-1);
	}
	return (1);
}

int			ft_printf(const char *format, ...)
{
	int		ret;
	va_list	ap;
	char	*tmp;

	tmp = ft_strdup(format);
	if (!tmp)
		return (-1);
	if (ft_check_format(tmp) < 0)
	{
		free(tmp);
		return (-1);
	}
	va_start(ap, format);
	ret = ft_putprintf((char*)format, ap);
	va_end(ap);
	free(tmp);
	tmp = NULL;
	return (ret);
}
