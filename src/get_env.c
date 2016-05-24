/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 13:39:21 by cmutti            #+#    #+#             */
/*   Updated: 2016/05/05 13:39:23 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			ft_atoi_mod(char *s, int *nbr)
{
	int		nb;
	int		i;

	nb = 0;
	i = (s[0] == '+' && ft_isdigit(s[1])) ? 1 : 0;
	while (i >= 0 && s[i])
	{
		if (nb == 214748364 && s[i] > '7')
			i = -2;
		else if (s[i] < '0' || s[i] > '9' || nb > 214748364)
			i = -2;
		else
		{
			nb = nb * 10 + s[i] - 48;
			i++;
		}
	}
	*nbr = nb;
	return (i);
}

int			add_line(t_line **start, char **str)
{
	t_line	*new;
	t_line	*tmp;

	tmp = *start;
	if (!(new = (t_line*)malloc(sizeof(*tmp))))
	{
		ft_strdel(str);
		return (0);
	}
	new->next = NULL;
	if (!(new->str = ft_strdup(*str)))
	{
		ft_strdel(str);
		return (0);
	}
	ft_strdel(str);
	if (!tmp)
		*start = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

static int	clear_str(char **str, int ret)
{
	if (str && *str)
		ft_strdel(str);
	return (ret);
}

int			get_env(t_env *env)
{
	char	*str;

	str = NULL;
	if (get_line(&str) <= 0 || ft_atoi_mod(str, &(env->ants)) < 0)
	{
		ft_strdel(&str);
		return (-1);
	}
	else if (!add_line(&(env->lines), &str))
		return (-2);
	if (get_rooms(env, &str) < 0)
		return (clear_str(&str, -3));
	if ((!env->start || !env->end))
		return (clear_str(&str, -4));
	if (get_connections(env, &str) < 0)
		return (clear_str(&str, -5));
	return (1);
}
