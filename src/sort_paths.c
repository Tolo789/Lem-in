/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 14:02:24 by cmutti            #+#    #+#             */
/*   Updated: 2016/05/15 14:02:26 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	switch_paths(t_env *env, int pos)
{
	t_path	*tmp1;
	t_path	*tmp2;
	int		i;

	tmp1 = env->paths;
	i = 0;
	if (!pos && env->paths && env->paths->down)
	{
		tmp2 = tmp1->down;
		env->paths = tmp2;
		tmp1->down = tmp2->down;
		tmp2->down = tmp1;
	}
	else if (env->paths && env->paths->down)
	{
		tmp2 = env->paths;
		while (i < pos && ++i)
		{
			tmp1 = tmp2;
			tmp2 = tmp2->down;
		}
		tmp1->down = tmp2->down;
		tmp2->down = tmp2->down->down;
		tmp1->down->down = tmp2;
	}
}

void		sort_paths(t_env *env)
{
	t_path	*tmp1;
	int		i;
	int		pos;

	i = 1;
	while (i)
	{
		tmp1 = env->paths;
		i = 0;
		pos = 0;
		while (tmp1->down && i == 0)
		{
			if (tmp1->down && tmp1->lenght != tmp1->down->lenght && ++pos)
				tmp1 = tmp1->down;
			else
				while (tmp1->down && tmp1->lenght == tmp1->down->lenght && !i)
				{
					if (tmp1->rounds > tmp1->down->rounds && (i = 1))
						switch_paths(env, pos);
					else if (++pos)
						tmp1 = tmp1->down;
				}
		}
	}
}
