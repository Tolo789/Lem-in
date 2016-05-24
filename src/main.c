/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 10:53:32 by cmutti            #+#    #+#             */
/*   Updated: 2016/05/05 10:53:34 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	free_lines(t_line **start)
{
	t_line	*tmp1;
	t_line	*tmp2;

	tmp1 = *start;
	while (tmp1)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		if (tmp2->str)
			free(tmp2->str);
		tmp2->next = NULL;
		free(tmp2);
		tmp2 = NULL;
	}
}

static void	free_rooms(t_room **start)
{
	t_room	*tmp1;
	t_room	*tmp2;

	tmp1 = *start;
	while (tmp1)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		free(tmp2->name);
		while (tmp2->c_nbr > 0)
		{
			tmp2->c_nbr -= 1;
			tmp2->connections[tmp2->c_nbr] = 0;
		}
		free(tmp2->connections);
		tmp2->connections = NULL;
		free(tmp2);
	}
}

static void	free_path(t_path **start)
{
	t_path	*tmp1;
	t_path	*tmp2;
	t_path	*tmp3;

	tmp1 = *start;
	while (tmp1 && tmp1->down)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->down;
		while (tmp2)
		{
			tmp3 = tmp2;
			tmp2 = tmp2->next;
			free(tmp3);
			tmp3 = NULL;
		}
	}
	while (tmp1)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		free(tmp2);
		tmp2 = NULL;
	}
}

static int	free_env(t_env *env)
{
	free_lines(&(env->lines));
	env->lines = NULL;
	free_rooms(&(env->rooms));
	env->rooms = NULL;
	free_path(&(env->paths));
	env->paths = NULL;
	env->start = NULL;
	env->end = NULL;
	return (1);
}

int			main(int argc, char **argv)
{
	t_env	env;

	env.rooms = NULL;
	env.paths = NULL;
	env.lines = NULL;
	env.ants = 0;
	env.p_nbr = 0;
	env.start = NULL;
	env.end = NULL;
	env.options = 0;
	env.sent = 0;
	env.rounds = 0;
	env.moves = 0;
	env.distance = 0;
	if (argc > 1 && get_options(argc, argv, &env) < 0)
		(env.options & 1) ? print_options() : ft_putstr("ERROR\n");
	else if (get_env(&env) < 0)
		ft_putstr("ERROR\n");
	else if (get_paths(&env) < 0)
		ft_putstr("ERROR\n");
	else
		resolve(&env);
	free_env(&env);
	return (0);
}
