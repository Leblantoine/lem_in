/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <aleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 09:40:30 by aleblanc          #+#    #+#             */
/*   Updated: 2016/05/11 10:45:34 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_ant
{
	int				id;
	char			*where;
	struct s_ant	*next;
}					t_ant;

typedef struct		s_tube
{
	char			*r1;
	char			*r2;
	int				b;
	struct s_tube	*next;
}					t_tube;

typedef struct		s_room
{
	char			*name;
	int				spe;
	int				x;
	int				y;
	int				oc;
	int				mark;
	char			*path;
	struct s_room	*next;
	struct s_room	**link;
}					t_room;

typedef struct		s_path
{
	int				len;
	int				select;
	int				min;
	struct s_room	**room;
	struct s_path	*next;
}					t_path;

typedef struct		s_all
{
	t_ant			*ant;
	t_room			*room;
	t_tube			*tube;
	t_path			*paths;
	int				nbant;
	int				nbpath;
	int				nbroom;
	int				turn;
	char			*file;
}					t_all;

t_all				*read_map(void);
int					check_nbant(char *map, t_all *all);
int					room_exists(t_room *room, char *str);
int					spe_exists(t_room *room, int spe);
int					check_tube(char *map, t_all *all);
int					check_room(char *map, t_all *all, int spe);
t_ant				*stock_ants(int nb);
t_room				*stock_room(char **tab, t_all *all, int spe);
t_tube				*stock_tube(char **tab, t_all *all);
void				stock_path(t_all *all, char *path);
void				in_loop(t_all *all);
void				in_loop_path(t_all *all);
void				in_loop_ant(t_all *all);
int					check_enough(t_all *all);
void				build_map(t_all *all);
int					find_paths(t_all *all);
int					check_path(t_all *all, t_room *room, char *start);
int					check_len(t_room *room, char *path);
void				move_ants(t_all *all);
void				select_path(t_all *all);
t_path				*find_min(t_all *all);
int					math(t_all *all, t_path *path, int tour);
int					check_double(t_all *all, t_path *search);
int					tabroomlen(t_room **link);
t_room				**add_to_tab(t_room **link, t_room *room);
void				option(char **tab, t_all *all);

#endif
