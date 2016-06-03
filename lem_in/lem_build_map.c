/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_build_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 09:06:57 by aleblanc          #+#    #+#             */
/*   Updated: 2016/04/29 17:19:24 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			tabroomlen(t_room **link)
{
	int		i;

	i = 0;
	while (link && link[i] != NULL)
		i++;
	return (i);
}

t_room		**add_to_tab(t_room **link, t_room *room)
{
	int		len;
	int		i;
	t_room	**new;

	if (link == NULL)
	{
		link = (t_room **)malloc(sizeof(t_room *) * 2);
		link[0] = room;
		link[1] = NULL;
		return (link);
	}
	else
	{
		i = -1;
		len = tabroomlen(link);
		new = (t_room **)malloc(sizeof(t_room *) * (len + 2));
		while (++i < len)
			new[i] = link[i];
		new[len] = room;
		new[len + 1] = NULL;
		return (new);
	}
}

void		build_map(t_all *all)
{
	t_room		*tmpr;

	in_loop(all);
	while (all->tube != NULL)
	{
		while (all->room)
		{
			tmpr = all->room;
			if (ft_strcmp(all->tube->r1, all->room->name) == 0)
			{
				while (all->room)
				{
					if (ft_strcmp(all->tube->r2, all->room->name) == 0)
					{
						tmpr->link = add_to_tab(tmpr->link, all->room);
						break ;
					}
					all->room = all->room->next;
				}
				break ;
			}
			all->room = tmpr->next;
		}
		all->tube = all->tube->next;
	}
}
