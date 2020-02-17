/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_suurballe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:44:44 by jflorent          #+#    #+#             */
/*   Updated: 2020/01/07 19:30:29 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		reset_ancestors(t_room *map)
{
	t_rconn	*link;

	link = map->lnks;
	while (link)
	{
		if (link->room->anc == map &&
			link->room->room_type != 1)
			link->room->anc = 0;
		link = link->next;
	}
}

static void		insert_in_chain(t_rconn *start, t_rconn *mid, t_rconn *end)
{
	start->next = mid;
	mid->prev = start;
	mid->next = end;
	end->prev = mid;
}

static t_rconn	*split_in_chain(t_rconn *top, t_room **map)
{
	t_room		*new_room;
	t_rconn		*new_conn;

	if (!(top->prev->room->split))
		conn_del_room_from_lnks(top->room, top->prev->room);
	else
		conn_del_room_from_lnks(top->room, top->prev->room->split_room);
	conn_del_room_from_lnks(top->prev->room, top->room);
	new_room = room_split(*map, top);
	new_conn = conn_create_elem(new_room, 1);
	ins_in_lnks(new_room, top->prev->room, 1);
	insert_in_chain(top->prev, new_conn, top);
	return (new_conn);
}

static void		change_splitroom(t_rconn *top)
{
	t_room		*old_split;

	old_split = top->room->split_room->lnks->room;
	if (old_split->room_type != 0)
	{
		conn_del_room_from_lnks(top->room->split_room, old_split);
		ins_in_lnks(old_split, top->room->split_room, 1);
		ins_in_lnks(top->room, old_split->split_room, 1);
		if (!(top->prev->prev->room->split))
			conn_del_room_from_lnks(top->room, top->prev->prev->room);
		else
			conn_del_room_from_lnks(top->room,
									top->prev->prev->room->split_room);
	}
	conn_del_room_from_lnks(top->prev->prev->room, top->room->split_room);
	ins_in_lnks(top->room->split_room, top->prev->prev->room, 1);
	reset_ancestors(top->prev->room);
	top->prev->room->anc = 0;
}

int				reverse_suur(t_rconn *top, t_room **map)
{
	while (top->next)
		top = top->next;
	while (top->room->room_type != 0)
	{
		reset_ancestors(top->room);
		top->room->anc = 0;
		if (top->room->room_type == 1)
		{
			conn_del_room_from_lnks(top->room, top->prev->room);
			if (top->room->lnks == 0)
				return (0);
			conn_del_room_from_lnks(top->prev->room, top->room);
			top = top->prev;
		}
		else if (!(top->room->split))
			top = (split_in_chain(top, map))->prev;
		else if (top->room->split)
		{
			change_splitroom(top);
			top = top->prev->prev;
		}
	}
	return (1);
}
