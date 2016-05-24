/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 16:58:36 by cmutti            #+#    #+#             */
/*   Updated: 2016/05/14 16:58:38 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_options(void)
{
	ft_putendl("\t\t\tHELP MENU");
	ft_putstr("-h\t\tdisplays help menu and closes program.\n");
	ft_putendl("-c\t\tcolors the movement when end room is reached by an ant.");
	ft_putstr("-d\t\tuses coordinates between rooms to workout the");
	ft_putstr(" actual lenght of each connection.\n");
	ft_putstr("-m\t\tenables multi-pathfinding.\n");
	ft_putstr("-p\t\tdisplays all found paths with their infos.\n");
	ft_putstr("-t\t\tshows total number of rounds and covered distance.\n");
}

int		get_options(int argc, char **argv, t_env *env)
{
	int		i;

	i = 1;
	while (argc > i)
	{
		if (ft_strequ("-h", argv[i]) && (i)++)
			env->options += !(env->options & 1) ? 1 : 0;
		else if (ft_strequ("-d", argv[i]) && (i)++)
			env->options += !(env->options & 2) ? 2 : 0;
		else if (ft_strequ("-p", argv[i]) && (i)++)
			env->options += !(env->options & 4) ? 4 : 0;
		else if (ft_strequ("-m", argv[i]) && (i)++)
			env->options += !(env->options & 8) ? 8 : 0;
		else if (ft_strequ("-c", argv[i]) && (i)++)
			env->options += !(env->options & 16) ? 16 : 0;
		else if (ft_strequ("-t", argv[i]) && (i)++)
			env->options += !(env->options & 32) ? 32 : 0;
		else
			return (-1);
	}
	if (env->options & 1)
		return (-1);
	return (1);
}
