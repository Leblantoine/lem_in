/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_ant_trip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 09:42:45 by aleblanc          #+#    #+#             */
/*   Updated: 2016/04/29 18:35:31 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			check_ant(t_all *all, int u)
{
	int		i;

	i = -1;
	while (all->room)
	{
		if (all->room->spe == u)
			break ;
		all->room = all->room->next;
	}
	if (u == 2)
	{
		if (all->room->oc != all->nbant)
			return (0);
		return (1);
	}
	else
	{
		if (all->room->oc != 0)
			return (0);
		return (1);
	}
}

void		ant_forward(t_path *path, t_ant *ant)
{
	int		i;

	i = path->len;
	while (--i >= 1)
	{
		if (path->room[i]->oc == 1)
		{
			path->room[i]->oc--;
			path->room[i + 1]->oc++;
			while (ant->where == NULL ||
					ft_strcmp(path->room[i]->name, ant->where) != 0)
				ant = ant->next;
			ant->where = path->room[i + 1]->name;
			ft_printf("L%d-%s ", ant->id, ant->where);
		}
	}
}

void		first_ant_move(t_all *all)
{
	all->paths->room[1]->oc++;
	while (all->ant->where != NULL)
		all->ant = all->ant->next;
	all->ant->where = all->paths->room[1]->name;
	all->paths->room[0]->oc--;
	ft_printf("L%d-%s ", all->ant->id, all->ant->where);
}

void		move_ants(t_all *all)
{
	int		i;

	in_loop_ant(all);
	while (!check_ant(all, 2))
	{
		i = -1;
		while (++i <= all->nbpath)
		{
			if (all->paths->select > 0)
			{
				ant_forward(all->paths, all->ant);
				if (!check_ant(all, 1) && (all->paths->len <=
							all->paths->room[0]->oc || all->paths->min == 1))
					first_ant_move(all);
			}
			all->paths = all->paths->next;
		}
		ft_putstr("\n");
		all->turn++;
	}
}
