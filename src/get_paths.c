/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:45:27 by cmutti            #+#    #+#             */
/*   Updated: 2016/05/09 11:45:30 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_room	*find_smaller_node(t_room **begin)
{
	t_room			*tmp;
	t_room			*save;
	unsigned int	min;

	tmp = *begin;
	save = NULL;
	min = -1;
	while (tmp)
	{
		if (!tmp->def && tmp->potential < min)
		{
			min = tmp->potential;
			save = tmp;
		}
		tmp = tmp->next;
	}
	return (save);
}

static int		is_last(t_room **begin, t_room *elem)
{
	t_room			*tmp;
	int				i;

	i = 0;
	while (i < elem->c_nbr)
	{
		tmp = *begin;
		while (tmp)
		{
			if (tmp->id == elem->connections[i] && tmp->end)
				return (1);
			tmp = tmp->next;
		}
		i++;
	}
	return (0);
}

unsigned int	get_tube_value(t_room *elem, t_room *tmp, t_env *env)
{
	unsigned int	value;

	value = 1;
	if (env->options & 2)
		value = ft_uisqr(ft_uipow((unsigned int)(elem->x - tmp->x), 2)
		+ ft_uipow((unsigned int)(elem->y - tmp->y), 2));
	return (value);
}

static int		rework_potential(t_room **begin, t_room *elem, t_env *e)
{
	t_room	*tmp;
	int		i;

	i = 0;
	if (is_last(begin, elem))
		return (1);
	while (i < elem->c_nbr)
	{
		tmp = *begin;
		while (tmp)
		{
			if (tmp->id == elem->connections[i] && !tmp->def &&
			tmp->potential > elem->potential + get_tube_value(elem, tmp, e))
			{
				tmp->prev_id = elem->id;
				tmp->potential = elem->potential + get_tube_value(elem, tmp, e);
				tmp->rounds = elem->rounds + 1;
				break ;
			}
			tmp = tmp->next;
		}
		i++;
	}
	return (0);
}

int				get_paths(t_env *env)
{
	t_room			*tmp;

	env->start->potential = 0;
	env->start->prev_id = env->start->id;
	env->start->rounds = 0;
	env->end->def = 1;
	if (env->start->id == env->end->id)
		return (1);
	env->start->rounds = 1;
	while ((tmp = find_smaller_node(&(env->rooms))))
	{
		tmp->def = 1;
		if (rework_potential(&(env->rooms), tmp, env))
		{
			if (!save_path(env, tmp))
				return (-1);
			else if (env->paths && can_stop(env))
				return (1);
		}
	}
	if (!env->paths && env->start->id != env->end->id)
		return (-1);
	return (1);
}
