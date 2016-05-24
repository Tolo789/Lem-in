/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 18:37:09 by cmutti            #+#    #+#             */
/*   Updated: 2016/05/14 18:37:11 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft/libft.h"

typedef struct		s_room
{
	char			*name;
	int				id;
	unsigned int	potential;
	int				def;
	int				x;
	int				y;
	int				end;
	int				start;
	int				prev_id;
	int				used;
	int				c_nbr;
	int				rounds;
	int				*connections;
	struct s_room	*next;
}					t_room;

typedef	struct		s_path
{
	char			*name;
	int				ant;
	unsigned int	lenght;
	int				rounds;
	struct s_path	*next;
	struct s_path	*down;
}					t_path;

typedef	struct		s_line
{
	char			*str;
	struct s_line	*next;
}					t_line;

typedef struct		s_env
{
	int				ants;
	int				sent;
	int				p_nbr;
	int				options;
	int				rounds;
	int				moves;
	unsigned int	distance;
	t_room			*rooms;
	t_room			*start;
	t_room			*end;
	t_path			*paths;
	t_line			*lines;
}					t_env;

int					get_options(int argc, char **argv, t_env *env);
int					get_env(t_env *env);
int					get_rooms(t_env *env, char **str);
int					get_connections(t_env *env, char **str);
int					get_paths(t_env *env);
int					save_path(t_env *env, t_room *elem);
void				sort_paths(t_env *env);
void				resolve(t_env *env);

unsigned int		get_tube_value(t_room *elem, t_room *tmp, t_env *env);
int					add_line(t_line **start, char **str);
int					is_connection(char *str);
int					get_line(char **str);
int					can_stop(t_env *env);
int					has_space(char *str);

void				print_lines(t_line **begin);
void				print_options(void);
void				print_found_paths(t_env *env);
void				print_move(int ant, char *name, int moved, t_env *env);
void				print_totals(t_env *env);

#endif
