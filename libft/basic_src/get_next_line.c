/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 11:36:36 by cmutti            #+#    #+#             */
/*   Updated: 2015/12/18 18:41:29 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#define BUFF_SIZE 80
#include "../libft.h"

static t_list	*ft_get_list_elem(t_list **begin, int fd)
{
	t_list			*tmp;

	if (!*begin)
	{
		tmp = ft_lstnew("\0", fd + 1);
		if (!tmp)
			return (NULL);
		ft_lstadd(begin, tmp);
	}
	tmp = *begin;
	while (tmp && tmp->content_size != (size_t)fd + 1)
		tmp = tmp->next;
	if (!tmp)
	{
		tmp = ft_lstnew("\0", fd + 1);
		if (!tmp)
			return (NULL);
		ft_lstadd(begin, tmp);
	}
	return (tmp);
}

static int		ft_getline(char **backup, char **line, int found)
{
	unsigned int	i;
	char			*tmp;

	if (found || ft_strchr(*backup, '\n'))
	{
		i = 0;
		found = 1;
		while (backup[0][i] != '\n')
			i++;
	}
	else
		i = ft_strlen(*backup);
	*line = ft_strsub(*backup, 0, i);
	if (found)
		i++;
	tmp = ft_strsub(*backup, i, ft_strlen(*backup) - i);
	if (backup && *backup)
		free(*backup);
	*backup = tmp;
	return ((i = (found || **line || **backup) ? 1 : 0));
}

static int		ft_end(t_list **item, char **line, int found, t_list **begin)
{
	t_list		*ptr;
	t_list		*tmp;
	size_t		fd;

	tmp = *item;
	fd = tmp->content_size;
	if (found >= 0)
		found = (ft_getline((char**)(&(tmp->content)), line, found));
	if (found <= 0)
	{
		ptr = *begin;
		while (ptr->content_size != fd && ptr->next->content_size != fd)
			ptr = ptr->next;
		if (ptr->content_size == fd)
			*begin = tmp->next;
		else
			ptr->next = tmp->next;
		if (tmp->content)
			free(tmp->content);
		free(tmp);
		tmp = NULL;
	}
	return (found);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*begin = NULL;
	t_list			*lst;
	char			str[BUFF_SIZE + 1];
	int				i;
	char			*s;

	if (fd < 0 || !line || fd > 16384)
		return (-1);
	lst = ft_get_list_elem(&begin, fd);
	if (!lst)
		return (-1);
	if (ft_strchr(lst->content, '\n'))
		return (ft_end(&lst, line, 1, &begin));
	while ((i = read(fd, str, BUFF_SIZE)) > 0)
	{
		str[i] = '\0';
		s = ft_strjoin(lst->content, str);
		if (lst->content)
			free(lst->content);
		lst->content = s;
		if (ft_strchr(str, '\n'))
			return (ft_getline((char**)&lst->content, line, 1));
	}
	return (ft_end(&lst, line, i, &begin));
}
