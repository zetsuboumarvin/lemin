/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_bford.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 13:11:55 by jflorent          #+#    #+#             */
/*   Updated: 2020/01/07 19:21:00 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		check_all_links(t_room *top)
{
	t_rconn		*link;
	int			count;

	link = top->lnks;
	count = 0;
	while (link)
	{
		if (link->room->weight > top->weight + link->weight)
		{
			link->room->weight = top->weight + link->weight;
			link->room->anc = top;
			count++;
		}
		link = link->next;
	}
	return (count);
}

static int		check_all_vertices(t_room **map)
{
	t_room		*top;
	int			count;

	top = *map;
	count = 0;
	while (top)
	{
		if (top->room_type != 1)
			count += check_all_links(top);
		top = top->next;
	}
	return (count);
}

t_rconn			*bford(t_room **map)
{
	static int		n;
	int				i;
	t_rconn			*shortest;
	t_room			*end;

	end = find_node(map, 1);
	if (!check_end_anc(end))
		return (0);
	if (n == 0)
		n = count_length_rooms(map);
	i = 0;
	shortest = 0;
	while (i < n - 1)
	{
		if (!check_all_vertices(map))
			break ;
		i++;
	}
	if (check_all_vertices(map))
		return (0);
	shortest = find_backward(end);
	return (shortest);
}
