/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_stock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 10:42:25 by aleblanc          #+#    #+#             */
/*   Updated: 2016/04/29 17:18:39 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_ant		*stock_ants(int nb)
{
	t_ant	*start;
	t_ant	*tmp;
	int		i;

	i = 1;
	start = (t_ant *)malloc(sizeof(t_ant));
	start->id = i++;
	start->where = NULL;
	tmp = start;
	nb--;
	while (nb > 0)
	{
		tmp->next = (t_ant *)malloc(sizeof(t_ant));
		tmp = tmp->next;
		tmp->id = i++;
		start->where = NULL;
		nb--;
	}
	return (start);
}

t_room		*stock_room(char **tab, t_all *all, int spe)
{
	t_room	*tmp;

	tmp = (t_room *)malloc(sizeof(t_room));
	tmp->name = tab[0];
	tmp->spe = spe;
	tmp->x = ft_atoi(tab[1]);
	tmp->y = ft_atoi(tab[2]);
	tmp->link = NULL;
	tmp->path = tab[0];
	tmp->mark = 0;
	if (spe == 1)
		tmp->oc = all->nbant;
	else
		tmp->oc = 0;
	tmp->next = all->room;
	return (tmp);
}

t_tube		*stock_tube(char **tab, t_all *all)
{
	t_tube	*tmp;
	t_tube	*new;
	t_tube	*rev;

	tmp = all->tube;
	while (tmp)
	{
		if (ft_strcmp(tmp->r1, tab[1]) == 0 && ft_strcmp(tmp->r2, tab[0]) == 0)
			return (all->tube);
		tmp = tmp->next;
	}
	new = (t_tube *)malloc(sizeof(t_tube));
	rev = (t_tube *)malloc(sizeof(t_tube));
	new->r1 = tab[0];
	rev->r1 = tab[1];
	new->r2 = tab[1];
	rev->r2 = tab[0];
	new->b = 0;
	rev->b = 0;
	new->next = rev;
	rev->next = all->tube;
	return (new);
}

void		stock_path(t_all *all, char *path)
{
	char	**tab;
	t_path	*new;
	int		i;

	i = -1;
	tab = ft_strsplit(path, '-');
	new = (t_path *)malloc(sizeof(t_path));
	new->len = ft_tablen(tab) - 1;
	new->select = 0;
	new->min = 0;
	while (tab[++i])
	{
		while (all->room)
		{
			if (ft_strcmp(all->room->name, tab[i]) == 0)
				break ;
			all->room = all->room->next;
		}
		new->room = add_to_tab(new->room, all->room);
	}
	new->next = all->paths;
	all->paths = new;
}
