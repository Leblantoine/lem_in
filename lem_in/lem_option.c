/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 18:04:06 by aleblanc          #+#    #+#             */
/*   Updated: 2016/05/11 10:20:18 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		show_used_path(t_all *all)
{
	int		i;
	int		u;

	i = -1;
	ft_putstr("Used path(s) :\n");
	while (++i <= all->nbpath)
	{
		if (all->paths->select > 0)
		{
			u = -1;
			while (all->paths->room[++u])
				ft_printf("%s ", all->paths->room[u]->name);
			ft_putchar('\n');
		}
		all->paths = all->paths->next;
	}
}

void		option(char **tab, t_all *all)
{
	int		i;

	i = 0;
	while (tab[++i])
	{
		ft_putchar('\n');
		if (ft_strcmp(tab[i], "-p") == 0)
			show_used_path(all);
		else if (ft_strcmp(tab[i], "-n") == 0)
			ft_printf("Number of turn : %d\n", all->turn);
		else
		{
			ft_putstr("OPTION USAGE\n   [-p] : show used path(s)\n");
			ft_putstr("   [-n] : show the number of turn\n");
			break ;
		}
	}
}
