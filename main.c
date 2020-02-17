/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:04:00 by clianne           #+#    #+#             */
/*   Updated: 2020/01/08 11:43:09 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <unistd.h>

static int			reset_weight_room(t_room **map, t_path *sol)
{
	t_room		*top;
	t_path		*top_p;

	top = *map;
	while (top)
	{
		if (top->room_type != 0)
		{
			top->inp_weight = LM_MAX;
			top->out_weight = LM_MAX;
			top->weight = LM_MAX;
		}
		top = top->next;
	}
	top_p = sol;
	while (top_p)
	{
		if (!reverse_suur(top_p->lnks, map))
			return (0);
		top_p = top_p->next;
	}
	return (1);
}

static t_path		*suurballe_sol(t_room **map)
{
	t_rconn		*result;
	t_path		*sol;
	int			max_effect;
	int			temp_effect;

	sol = 0;
	path_push_back(&sol, do_alg_dijkstra(map));
	max_effect = check_effect(&sol, map, 0);
	while (1)
	{
		if (!reset_weight_room(map, sol))
			break ;
		if (!(result = bford(map)))
			break ;
		path_oper_intersection(&sol, result);
		if ((temp_effect = check_effect(&sol, map, 0)) >= max_effect)
			break ;
		else
			max_effect = temp_effect;
	}
	return (sol);
}

int					main(void)
{
	t_room	*map;
	t_path	*sol;

	map = 0;
	if (!map_read(&map))
	{
		map_free(&map);
		ft_putstr(LEMIN_ERROR);
	}
	if (map)
	{
		sol = suurballe_sol(&map);
		check_effect(&sol, &map, 1);
		path_lst_del(&sol, 1);
		map_free(&map);
	}
	return (0);
}
