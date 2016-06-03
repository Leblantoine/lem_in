/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 08:38:52 by aleblanc          #+#    #+#             */
/*   Updated: 2016/05/11 10:42:31 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		error(void)
{
	write(1, "ERROR\n", 6);
	return (0);
}

int		main(int argc, char **argv)
{
	t_all	*all;

	all = read_map();
	if (!check_enough(all))
		return (error());
	build_map(all);
	if (!find_paths(all))
		return (error());
	ft_putstr(all->file);
	ft_putchar('\n');
	in_loop_path(all);
	if (all->nbpath > 0)
	{
		select_path(all);
		move_ants(all);
	}
	else
		return (error());
	if (argc > 1)
		option(argv, all);
	return (0);
}
