/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:25:04 by clianne           #+#    #+#             */
/*   Updated: 2020/01/08 11:08:40 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** to find room by name
*/

t_room			*room_find_by_name(t_room *map, char *room_name)
{
	t_room	*node;

	if (!room_name || !map)
		return (NULL);
	node = map;
	while (node)
	{
		if (!ft_strcmp(node->room_name, room_name))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/*
** to get map by room name
*/

t_room			*room_find_by_room(t_rconn *head, t_room *node)
{
	t_rconn	*tmp;

	if (!head || !node)
		return (0);
	tmp = head;
	while (tmp)
	{
		if (tmp->room == node)
			return (tmp->room);
		tmp = tmp->next;
	}
	return (0);
}

/*
** to return with code
*/

static size_t	ret_room_create(char **els, size_t code)
{
	ft_strlist_del(els);
	return (code);
}

/*
** to create room and return func
*/

size_t			room_create(t_room **map, char *line, int *room_type)
{
	char	**els;

	if (!line || line[0] == '#')
		return (0);
	els = ft_strsplit(line, ' ');
	if (room_find_by_name(*map, els[0]) || !room_check_xy(els))
		return (ret_room_create(els, 0));
	map_push_back(map, els, *room_type);
	*room_type = -1;
	return (ret_room_create(els, 1));
}

/*
** to split room and to add to end of map list
*/

t_room			*room_split(t_room *map, t_rconn *conn_to_split)
{
	t_room	*room_to_split;
	t_room	*new_room;
	t_rconn	*lnks;
	t_room	*buf;

	room_to_split = conn_to_split->room;
	if (!room_to_split)
		return (0);
	room_to_split->split = 1;
	if (!(new_room = map_push_back(&map, &(room_to_split->room_name), -2)))
		return (0);
	lnks = room_to_split->lnks;
	new_room->split_room = room_to_split;
	room_to_split->split_room = new_room;
	while (lnks)
	{
		buf = (lnks->room->room_type == -2) ? lnks->room->split_room :
			lnks->room;
		conn_del_room_from_lnks(buf, room_to_split);
		ins_in_lnks(buf, new_room, 1);
		lnks = lnks->next;
	}
	conn_push_back(&(room_to_split->lnks), new_room, 0);
	return (new_room);
}
