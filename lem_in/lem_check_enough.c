/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_check_enough.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 13:32:13 by aleblanc          #+#    #+#             */
/*   Updated: 2016/04/29 16:45:18 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_enough(t_all *all)
{
	t_room		*room;
	int			i;
	int			u;

	if (all->nbant == 0 || all->tube == NULL || all->room == NULL)
		return (0);
	room = all->room;
	i = 0;
	u = 0;
	while (room)
	{
		if (room->spe == 1)
			i++;
		else if (room->spe == 2)
			u++;
		room = room->next;
	}
	if (i != 1 || u != 1)
		return (0);
	return (1);
}
