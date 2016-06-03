/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_select_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:50:00 by aleblanc          #+#    #+#             */
/*   Updated: 2016/04/29 17:50:54 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_path		*find_min(t_all *all)
{
	int		i;
	int		min;
	t_path	*re;

	i = -1;
	min = 2147483647;
	re = all->paths;
	while (++i <= all->nbpath)
	{
		if ((min >= all->paths->len && all->paths->select == 0))
		{
			min = all->paths->len;
			re = all->paths;
		}
		all->paths = all->paths->next;
	}
	return (re);
}

int			check_double(t_all *all, t_path *search)
{
	int		i;
	int		u;
	int		z;

	i = -1;
	while (++i <= all->nbpath)
	{
		if (all->paths->select > 0)
		{
			u = -1;
			while (all->paths->room && all->paths->room[++u])
			{
				z = 0;
				while (z < search->len - 1 && search->room && search->room[++z])
				{
					if (ft_strcmp(search->room[z]->name,
								all->paths->room[u]->name) == 0)
						return (0);
				}
			}
		}
		all->paths = all->paths->next;
	}
	return (1);
}

int			math(t_all *all, t_path *path, int tour)
{
	int		i;

	i = 1;
	if (tour == -1)
	{
		tour = path->len == 1 ? all->nbant : path->len + all->nbant - 1;
		path->select = tour;
	}
	else
	{
		while (tour >= path->len + i - 1)
			i++;
		if (i >= path->len && tour != -1)
		{
			if (check_double(all, path) && tabroomlen(path->room) != 2)
			{
				path->select = i;
				tour = i;
			}
			else
				path->select = -1;
		}
	}
	return (tour);
}

void		select_path(t_all *all)
{
	int		tour;
	int		i;
	t_path	*min;

	i = -1;
	tour = -1;
	min = find_min(all);
	min->min = 1;
	while (++i <= all->nbpath)
	{
		tour = math(all, min, tour);
		all->paths = all->paths->next;
		min = find_min(all);
	}
}
