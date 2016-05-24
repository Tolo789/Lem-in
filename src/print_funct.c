/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 10:27:46 by cmutti            #+#    #+#             */
/*   Updated: 2016/05/09 10:27:49 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		print_lines(t_line **begin)
{
	t_line	*tmp;

	tmp = *begin;
	while (tmp)
	{
		ft_putendl(tmp->str);
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

static void	print_paths_sequence(t_path *tmp)
{
	if (!tmp)
		return ;
	print_paths_sequence(tmp->next);
	if (tmp->next)
		ft_putstr(" - ");
	ft_putstr(tmp->name);
}

void		print_found_paths(t_env *env)
{
	t_path *tmp1;

	ft_putstr("Paths found:\n");
	tmp1 = env->paths;
	while (tmp1)
	{
		ft_putstr("Path sequence: ");
		print_paths_sequence(tmp1->next);
		if (tmp1->next)
			ft_putstr(" - ");
		ft_putstr(tmp1->name);
		(env->options & 2) ? ft_putstr(". Lenght: ") : 0;
		(env->options & 2) ? ft_putunbr(tmp1->lenght) : 0;
		ft_putstr(". Rounds: ");
		ft_putnbr(tmp1->rounds);
		ft_putstr(".\n");
		tmp1 = tmp1->down;
	}
	ft_putchar('\n');
}

void		print_move(int ant, char *name, int moved, t_env *env)
{
	if (env->options & 16 && ft_strequ(name, env->end->name))
		ft_putstr("\033[33m");
	(moved > 1) ? ft_putstr(" L") : ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(name);
	if (env->options & 16 && ft_strequ(name, env->end->name))
		ft_putstr("\033[0m");
}

void		print_totals(t_env *env)
{
	ft_putstr("\nTotal Rounds: ");
	ft_putnbr(env->rounds);
	ft_putstr(".\nTotal Moves: ");
	ft_putnbr(env->moves);
	(env->options & 2) ? ft_putstr(".\nTotal Distance: ") : 0;
	(env->options & 2) ? ft_putunbr(env->distance) : 0;
	ft_putstr(".\n");
}
