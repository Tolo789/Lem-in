/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_connections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 10:00:35 by cmutti            #+#    #+#             */
/*   Updated: 2016/05/09 10:00:37 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_room	*find_room(t_room **begin, char *str, int i, int choice)
{
	t_room	*tmp;
	int		j;

	tmp = *begin;
	if (choice == 1)
		while (tmp)
		{
			j = 0;
			while (str[j] && tmp->name[j] && str[j] == tmp->name[j])
				j++;
			if (j == i && tmp->name[j] == '\0')
				break ;
			tmp = tmp->next;
		}
	else
		while (tmp)
		{
			j = 0;
			while (str[i + j] && tmp->name[j] && str[i + j] == tmp->name[j])
				j++;
			if (str[i + j] == '\0' && tmp->name[j] == '\0')
				break ;
			tmp = tmp->next;
		}
	return (tmp);
}

static int		add_connection(t_room *room, int id)
{
	int		*tab;
	int		i;

	tab = room->connections;
	room->c_nbr += 1;
	if (!(room->connections = (int*)malloc(sizeof(int) * (room->c_nbr))))
		return (0);
	i = 0;
	while (i + 1 < room->c_nbr)
	{
		room->connections[i] = tab[i];
		i++;
	}
	room->connections[i] = id;
	if (tab)
		free(tab);
	return (1);
}

static int		check_connection(t_room **begin, char *str, int i)
{
	t_room	*tmp1;
	t_room	*tmp2;

	tmp1 = find_room(begin, str, i, 1);
	i++;
	tmp2 = find_room(begin, str, i, 2);
	if (!tmp1 || !tmp2 || ft_strequ(tmp1->name, tmp2->name))
		return (0);
	if (!add_connection(tmp1, tmp2->id) || !add_connection(tmp2, tmp1->id))
		return (-1);
	return (1);
}

int				get_connections(t_env *env, char **str)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (str[0][0] == '#')
		{
			if (ft_strequ("##start", *str) || ft_strequ("##end", *str))
				return (-1);
		}
		else if (str[0][0] == 'L' || !ft_strchr(*str, '-'))
			return (0);
		else if ((i = ft_strchr(*str, '-') - *str) <= 0)
			return (0);
		else if ((i = check_connection(&(env->rooms), *str, i)) <= 0)
			return (i);
		if (!add_line(&(env->lines), str))
			return (-2);
		if (get_line(str) < 0)
			return (-1);
	}
	return (i);
}
