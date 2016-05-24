/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 18:44:29 by cmutti            #+#    #+#             */
/*   Updated: 2016/05/14 18:44:30 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	advance_ants(t_env *e)
{
	t_path	*t1;
	t_path	*tmp2;
	int		i;

	t1 = e->paths;
	i = 0;
	while (e->options & 8 && t1->down)
	{
		tmp2 = t1;
		t1 = t1->down;
		while (tmp2)
		{
			tmp2->ant = (tmp2->next && tmp2->next->ant) ? tmp2->next->ant : 0;
			if (tmp2->ant && tmp2->next && ++i)
				print_move(tmp2->ant, tmp2->name, i, e);
			tmp2 = tmp2->next;
		}
	}
	while (t1)
	{
		t1->ant = (t1->next && t1->next->ant) ? t1->next->ant : 0;
		(t1->ant && t1->next && ++i) ? print_move(t1->ant, t1->name, i, e) : 0;
		t1 = t1->next;
	}
	return (i);
}

static void	cut_funct(t_env *env, t_path **tmp2, int i, int moved)
{
	env->distance += (*tmp2)->lenght;
	while ((*tmp2)->next)
		(*tmp2) = (*tmp2)->next;
	(*tmp2)->ant = env->sent + i;
	print_move((*tmp2)->ant, (*tmp2)->name, i + moved, env);
}

static int	start_ants(t_env *env, int moved)
{
	t_path	*tmp1;
	t_path	*tmp2;
	int		i;

	tmp2 = env->paths;
	tmp1 = (env->paths) ? env->paths->down : NULL;
	if (tmp2 && !(i = 0) && env->sent + i < env->ants && ++i)
	{
		env->distance += tmp2->lenght;
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp2->ant = env->sent + i;
		print_move(tmp2->ant, tmp2->name, i + moved, env);
	}
	while (env->options & 8 && tmp1 &&
		tmp1->rounds - env->paths->rounds < env->ants - env->sent - i)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->down;
		if (env->sent + i < env->ants && ++i)
			cut_funct(env, &tmp2, i, moved);
	}
	return (i);
}

void		resolve(t_env *env)
{
	int		moves;
	int		sent;
	int		i;

	print_lines(&(env->lines));
	(env->options & 2 && env->paths) ? sort_paths(env) : 0;
	(env->options & 4) ? print_found_paths(env) : 0;
	i = 1;
	while (i && env->paths)
	{
		i = 0;
		moves = 0;
		sent = 0;
		moves += advance_ants(env);
		sent += start_ants(env, moves);
		env->sent += sent;
		i = moves + sent;
		env->moves += i;
		env->rounds += (i) ? 1 : 0;
		(i) ? ft_putchar('\n') : 0;
	}
	(env->options & 32) ? print_totals(env) : 0;
}
