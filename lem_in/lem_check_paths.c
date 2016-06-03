/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_check_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:01:41 by aleblanc          #+#    #+#             */
/*   Updated: 2016/04/29 17:04:50 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_len(t_room *room, char *path)
{
	int		i;
	int		nbtp;
	int		nbtr;

	nbtp = 0;
	nbtr = 0;
	i = -1;
	while (path[++i])
		if (path[i] == '-')
			nbtp++;
	i = -1;
	while (room->path[++i])
		if (path[i] == '-')
			nbtr++;
	if (nbtr > 0 && nbtp + 1 > nbtr)
		return (0);
	return (1);
}

int		check_path(t_all *all, t_room *room, char *start)
{
	int		i;
	int		ok;

	i = -1;
	while (room)
	{
		if (room->spe == 2)
			break ;
		room = room->next;
	}
	i = -1;
	ok = 0;
	while (room->link && room->link[++i])
	{
		if (ft_strstr(room->link[i]->path, start) != NULL)
		{
			stock_path(all, ft_strjoin(room->link[i]->path,
						ft_strjoin("-", room->name)));
			ok++;
		}
	}
	return (ok);
}
