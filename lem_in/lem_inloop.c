/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_inloop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:07:50 by aleblanc          #+#    #+#             */
/*   Updated: 2016/05/11 10:32:42 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	in_loop(t_all *all)
{
	t_room		*start;
	t_room		*tmp;
	int			i;

	i = 0;
	start = all->room;
	tmp = start;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	all->nbroom = i;
	tmp->next = start;
	all->room = start;
}

void	in_loop_path(t_all *all)
{
	t_path		*start;
	t_path		*tmp;
	int			i;

	i = 0;
	start = all->paths;
	tmp = start;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	all->nbpath = i;
	if (i > 0)
	{
		tmp->next = start;
		all->paths = start;
	}
}

void	in_loop_ant(t_all *all)
{
	t_ant		*start;
	t_ant		*tmp;
	int			i;

	i = 0;
	start = all->ant;
	tmp = start;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	tmp->next = start;
	all->ant = start;
}
