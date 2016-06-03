/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_check_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:32:18 by aleblanc          #+#    #+#             */
/*   Updated: 2016/05/11 09:46:52 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_nbant(char *map, t_all *all)
{
	long long	nb;

	if (ft_strisdigit(map) && ft_strlen(map) < 11
			&& (nb = ft_atoill(map)) < 2147483648 && nb != 0)
	{
		all->nbant = (int)nb;
		all->ant = stock_ants(ft_atoi(map));
	}
	else
		return (0);
	all->file = ft_strjoin(all->file, ft_strjoin(map, "\n"));
	return (1);
}

int		room_exists(t_room *room, char *str)
{
	t_room	*tmp;

	tmp = room;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, str) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		spe_exists(t_room *room, int spe)
{
	t_room	*tmp;

	tmp = room;
	while (tmp)
	{
		if (tmp->spe == spe)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		check_tube(char *map, t_all *all)
{
	char	**tab;
	int		len;

	tab = ft_strsplit(map, '-');
	len = ft_tablen(tab);
	if (len == 2 && room_exists(all->room, tab[0]) &&
			room_exists(all->room, tab[1]) && ft_strcmp(tab[0], tab[1]) != 0)
		all->tube = stock_tube(tab, all);
	else
		return (0);
	all->file = ft_strjoin(all->file, ft_strjoin(map, "\n"));
	return (2);
}

int		check_room(char *map, t_all *all, int spe)
{
	char	**tab;
	int		len;
	int		i;

	tab = ft_strsplit(map, ' ');
	len = ft_tablen(tab);
	i = 0;
	while (map[i])
		if (map[i++] == '-')
			return (0);
	if (len == 3 && tab[0][0] != 'L' && !room_exists(all->room, tab[0]) &&
			ft_strisdigit(tab[1]) && ft_strisdigit(tab[2]))
		all->room = stock_room(tab, all, spe);
	else
		return (0);
	all->file = ft_strjoin(all->file, ft_strjoin(map, "\n"));
	return (1);
}
