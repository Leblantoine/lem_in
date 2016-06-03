/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 08:33:45 by aleblanc          #+#    #+#             */
/*   Updated: 2016/05/11 09:46:47 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_all_help(char *map, t_all *all)
{
	if (ft_strcmp(map, "##end") == 0 && !spe_exists(all->room, 2))
	{
		all->file = ft_strjoin(all->file, ft_strjoin(map, "\n"));
		get_next_line(0, &map);
		while (map[0] == '#' && map[1] != '#')
		{
			all->file = ft_strjoin(all->file, ft_strjoin(map, "\n"));
			get_next_line(0, &map);
		}
		if (!check_room(map, all, 2))
			return (check_tube(map, all));
		else
			return (1);
	}
	else
	{
		if (!check_room(map, all, 0))
			return (check_tube(map, all));
		else
			return (1);
	}
}

int		check_all(char *map, t_all *all, int what)
{
	if (what == 0)
		return (check_nbant(map, all));
	else if (what == 1)
	{
		if (ft_strcmp(map, "##start") == 0 && !spe_exists(all->room, 1))
		{
			all->file = ft_strjoin(all->file, ft_strjoin(map, "\n"));
			get_next_line(0, &map);
			while (map[0] == '#' && map[1] != '#')
			{
				all->file = ft_strjoin(all->file, ft_strjoin(map, "\n"));
				get_next_line(0, &map);
			}
			if (!check_room(map, all, 1))
				return (check_tube(map, all));
			else
				return (1);
		}
		return (check_all_help(map, all));
	}
	else
		return (check_tube(map, all));
}

t_all	*read_map(void)
{
	char	*map;
	t_all	*all;
	int		what;

	what = 0;
	all = (t_all *)malloc(sizeof(t_all));
	all->nbant = 0;
	all->turn = 0;
	all->file = "\0";
	all->ant = NULL;
	all->room = NULL;
	all->tube = NULL;
	all->paths = NULL;
	while (get_next_line(0, &map) > 0 && map[0] != '\0')
	{
		if (map[0] == '#' && map[1] != '#')
			all->file = ft_strjoin(all->file, ft_strjoin(map, "\n"));
		else if (map[0] == '#' && map[1] == '#' && ft_strcmp(map, "##end") != 0
				&& ft_strcmp(map, "##start") != 0)
			all->file = ft_strjoin(all->file, ft_strjoin(map, "\n"));
		else if ((what = check_all(map, all, what)) == 0)
			break ;
	}
	return (all);
}
