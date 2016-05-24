/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 15:06:36 by cmutti            #+#    #+#             */
/*   Updated: 2016/05/05 15:06:38 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			get_coord(char *s, int *i, t_room **new, char next_char)
{
	int		nb;
	int		j;
	int		sign;

	nb = 0;
	sign = (s[*i] == '-' && ft_isdigit(s[*i + 1]) && (*i += 1)) ? 1 : 0;
	*i += (s[*i] == '+' && ft_isdigit(s[*i + 1])) ? 1 : 0;
	j = (s[*i]) ? 1 : -1;
	while (j == 1)
	{
		if (nb == 214748364 && ((sign && s[*i] > 56) || (!sign && s[*i] > 55)))
			j = -2;
		else if (s[*i] < 48 || s[*i] > 57 || nb > 214748364)
			j = -2;
		else
		{
			nb = nb * 10 + s[*i] - 48;
			++(*i);
		}
	}
	(sign) ? nb = -nb : 0;
	(next_char == ' ') ? (*new)->x = nb : 0;
	(next_char == '\0') ? (*new)->y = nb : 0;
	(j == -2 && s[*i] == next_char && ++(*i)) ? j = 0 : 0;
	return (j);
}

static int	get_room_values(t_room **new, char **str)
{
	int		i;

	i = 0;
	while (str[0][i] && str[0][i] != ' ')
		i++;
	if (!str[0][i] || i == 0 || !((*new)->name = ft_strsub(*str, 0, i)))
		return (-1);
	i++;
	if (!str[0][i])
		return (-1);
	if (get_coord(*str, &i, new, ' ') < 0)
		return (-1);
	if (get_coord(*str, &i, new, '\0') < 0)
		return (-1);
	(*new)->used = 0;
	(*new)->next = NULL;
	(*new)->potential = -1;
	(*new)->def = 0;
	(*new)->c_nbr = 0;
	(*new)->connections = NULL;
	return (i);
}

static int	check_compatibility(t_env *env, t_room **new, int i)
{
	t_room	*tmp;
	t_room	*tmp2;

	tmp = env->rooms;
	tmp2 = NULL;
	while (i >= 0 && tmp && ++i)
	{
		tmp2 = tmp;
		(tmp->start && (*new)->start) ? i = -1 : 0;
		(tmp->end && (*new)->end) ? i = -1 : 0;
		(ft_strequ((*new)->name, tmp->name)) ? i = -1 : 0;
		((*new)->x == tmp->x && (*new)->y == tmp->y) ? i = -1 : 0;
		tmp = tmp->next;
	}
	if (i < 0)
	{
		ft_strdel(&((*new)->name));
		free((*new));
		(*new) = NULL;
		return (-2);
	}
	(*new)->id = (!tmp2) ? 1 : i + 1;
	(tmp2) ? tmp2->next = (*new) : 0;
	(!tmp2) ? env->rooms = (*new) : 0;
	return (1);
}

static int	add_room(t_env *env, char **str, int *start, int *end)
{
	t_room	*new;
	int		i;

	i = 0;
	new = NULL;
	if (!(new = (t_room*)malloc(sizeof(*new))))
		return (-1);
	if (get_room_values(&new, str) < 0)
	{
		if (new->name)
			ft_strdel(&(new->name));
		free(new);
		new = NULL;
		return (-2);
	}
	new->start = *start;
	(*start) ? env->start = new : 0;
	*start = 0;
	new->end = *end;
	(*end) ? env->end = new : 0;
	*end = 0;
	return (check_compatibility(env, &new, i));
}

int			get_rooms(t_env *env, char **str)
{
	int		start;
	int		end;

	start = 0;
	end = 0;
	while (1)
	{
		if (get_line(str) < 0 || !(*str))
			return (-1);
		else if (str[0][0] == '#')
		{
			(ft_strequ("##start", *str)) ? start = 1 : 0;
			(ft_strequ("##end", *str)) ? end = 1 : 0;
		}
		else if (str[0][0] == 'L' || str[0][0] == ' ')
			return (-2);
		else if (!has_space(*str) || is_connection(*str))
			break ;
		else if (add_room(env, str, &start, &end) < 0)
			return (-3);
		if (!add_line(&(env->lines), str))
			return (-4);
	}
	return ((end || start) ? -2 : 1);
}
