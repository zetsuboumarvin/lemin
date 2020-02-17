/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:15:50 by jflorent          #+#    #+#             */
/*   Updated: 2020/01/08 11:39:29 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room			*find_node(t_room **map, int type)
{
	t_room		*top;

	top = *map;
	while (top)
	{
		if (top->room_type == type)
			return (top);
		top = top->next;
	}
	return (0);
}

int				count_length_rooms(t_room **map)
{
	t_room		*top;
	int			count;

	count = 0;
	top = *map;
	while (top)
	{
		count++;
		top = top->next;
	}
	return (count);
}

int				check_end_anc(t_room *top)
{
	t_rconn		*link;

	link = top->lnks;
	while (link)
	{
		if (link->weight != -1)
			return (1);
		link = link->next;
	}
	return (0);
}

t_rconn			*find_backward(t_room *top)
{
	t_room		*node;
	t_rconn		*resolve;

	node = top;
	resolve = 0;
	if (!check_end_anc(top))
		return (0);
	while (node)
	{
		conn_push_front(&resolve, node, 1);
		node = node->anc;
	}
	if (resolve->room->room_type != 0)
	{
		conn_lst_del(&resolve);
		resolve = 0;
	}
	return (resolve);
}
