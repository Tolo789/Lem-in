/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 19:11:30 by cmutti            #+#    #+#             */
/*   Updated: 2016/05/09 19:11:32 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_path	*add_end_path(t_env *env, t_room *elem)
{
	t_path	*new;
	t_room	*tmp1;
	t_room	*tmp2;
	int		i;

	i = 1;
	if (!(new = (t_path*)malloc(sizeof(*new))))
		return (NULL);
	env->end->used = 1;
	new->name = env->end->name;
	new->ant = 0;
	new->lenght = 0;
	new->lenght = elem->potential + get_tube_value(elem, env->end, env);
	tmp1 = elem;
	while (tmp1->id != tmp1->prev_id && ++i)
	{
		tmp2 = env->rooms;
		while (tmp2->id != tmp1->prev_id)
			tmp2 = tmp2->next;
		tmp1 = tmp2;
	}
	new->rounds = i;
	new->next = NULL;
	new->down = NULL;
	return (new);
}

static t_path	*add_path(t_env *env, t_room *elem)
{
	t_path	*new;
	t_room	*tmp;
	int		i;

	i = 1;
	if (!(new = (t_path*)malloc(sizeof(*new))))
		return (NULL);
	elem->used = 1;
	new->name = elem->name;
	new->ant = 0;
	new->lenght = 0;
	new->lenght = elem->potential + get_tube_value(elem, env->end, env);
	while (elem->id != elem->prev_id && ++i)
	{
		tmp = env->rooms;
		while (tmp->id != elem->prev_id)
			tmp = tmp->next;
		elem = tmp;
	}
	new->rounds = i;
	new->next = NULL;
	new->down = NULL;
	return (new);
}

static int		reset_rooms(t_env *env)
{
	t_room	*tmp;

	tmp = env->rooms;
	while (tmp)
	{
		if (!tmp->used)
		{
			tmp->potential = -1;
			tmp->def = 0;
		}
		tmp = tmp->next;
	}
	env->start->def = 0;
	env->start->potential = 0;
	return (1);
}

static void		remove_start_end_connection(t_env *env)
{
	int		i;

	i = 0;
	while (env->start->connections[i] != env->end->id)
		i++;
	while (i + 1 < env->start->c_nbr)
	{
		env->start->connections[i] = env->start->connections[i + 1];
		i++;
	}
	env->start->connections[i] = 0;
	env->start->c_nbr -= 1;
}

int				save_path(t_env *env, t_room *elem)
{
	t_path	*p_tmp;
	t_room	*r_tmp;

	env->p_nbr += 1;
	p_tmp = env->paths;
	while (p_tmp && p_tmp->down)
		p_tmp = p_tmp->down;
	(p_tmp) ? p_tmp->down = add_end_path(env, elem) : 0;
	(!p_tmp) ? env->paths = add_end_path(env, elem) : 0;
	if (!env->paths || (p_tmp && !p_tmp->down))
		return (0);
	p_tmp = (!p_tmp) ? env->paths : p_tmp->down;
	if (elem->id == env->start->id)
		remove_start_end_connection(env);
	while (elem->prev_id != elem->id)
	{
		if (!(p_tmp->next = add_path(env, elem)))
			return (0);
		p_tmp = p_tmp->next;
		r_tmp = env->rooms;
		while (r_tmp->id != elem->prev_id)
			r_tmp = r_tmp->next;
		elem = r_tmp;
	}
	return (reset_rooms(env));
}
