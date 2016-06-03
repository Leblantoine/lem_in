/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_find_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 10:00:11 by aleblanc          #+#    #+#             */
/*   Updated: 2016/04/29 17:11:55 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	**make_q(t_room *room, t_room **q, int u, int i)
{
	if (u == 1)
		q = add_to_tab(q, room);
	while (room->link && room->link[i])
	{
		if (room->link[i]->spe == 2)
			i++;
		q = add_to_tab(q, room->link[i]);
		i++;
	}
	return (q);
}

void	delete_mark(t_all *all)
{
	int		i;

	i = -1;
	while (++i <= all->nbroom)
	{
		all->room->mark = 0;
		all->room->path = all->room->name;
		all->room = all->room->next;
	}
	while (all->room->spe != 1)
		all->room = all->room->next;
}

void	find_paths_help(t_all *all, t_room *room, char *path, int u)
{
	t_room		**q;
	char		*tmp;
	int			i;

	tmp = path;
	q = NULL;
	q = make_q(room, q, 1, u);
	while (q[0] != NULL)
	{
		q = make_q(q[0], q, 0, 0);
		q[0]->mark = 1;
		path = q[0]->path;
		i = -1;
		while (q[0]->link && q[0]->link[++i])
			if (check_len(q[0]->link[i], q[0]->path)
					&& q[0]->link[i]->mark == 0)
			{
				q[0]->link[i]->path = ft_strjoin(path,
						ft_strjoin("-", q[0]->link[i]->name));
				check_path(all, q[0]->link[i], tmp);
			}
		q++;
		while (q[0] && q[0]->mark == 1)
			q++;
	}
}

int		find_paths(t_all *all)
{
	int		len;
	int		i;

	i = -1;
	while (all->room)
	{
		if (all->room->spe == 1)
			break ;
		all->room = all->room->next;
	}
	len = tabroomlen(all->room->link);
	while (++i < len)
	{
		find_paths_help(all, all->room, all->room->path, i);
		delete_mark(all);
	}
	return (1);
}
