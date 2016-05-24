/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 19:45:52 by cmutti            #+#    #+#             */
/*   Updated: 2016/05/15 19:45:55 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			is_connection(char *str)
{
	int		i;
	int		space;

	i = 0;
	space = 0;
	while (str[i])
	{
		if (str[i] == '-')
			break ;
		i++;
	}
	if ((str[i] && i == 0) || (str[i] && str[i - 1] != ' '))
		return (1);
	return (0);
}

static char	*join_free(char *str, char c)
{
	int		i;
	char	*new;

	i = (str) ? ft_strlen(str) + 1 : 1;
	if (!(new = ft_strnew(i)))
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = c;
	new[i + 1] = '\0';
	if (str)
		free(str);
	return (new);
}

int			get_line(char **str)
{
	int		i;
	int		ret;
	char	buff[1];
	char	*tmp;

	i = 0;
	tmp = NULL;
	while ((ret = read(0, buff, 1)) > 0)
	{
		if (buff[0] == '\n')
			break ;
		if (!(tmp = join_free(tmp, buff[0])))
			return (-1);
	}
	*str = tmp;
	if (ret < 0)
		return (ret);
	return ((!tmp || !(*tmp)) ? 0 : 1);
}

int			can_stop(t_env *env)
{
	t_path	*tmp;

	tmp = NULL;
	if (!(env->options & 8) && !(env->options & 2))
		return (1);
	if (!(env->options & 8))
	{
		tmp = env->paths;
		while (tmp->down && tmp->down->down)
			tmp = tmp->down;
		if (tmp->down && tmp->lenght < tmp->down->lenght)
			return (1);
	}
	return (0);
}

int			has_space(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	return ((str[i] == ' ') ? 1 : 0);
}
