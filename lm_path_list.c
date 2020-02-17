/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_path_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:14:35 by clianne           #+#    #+#             */
/*   Updated: 2020/01/03 13:59:37 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** to create path element
*/

t_path		*path_create_elem(t_rconn *rconn)
{
	t_path	*node;

	if (!(node = (t_path *)malloc(sizeof(t_path))))
		return (0);
	node->lnks = rconn;
	node->prev = 0;
	node->next = 0;
	node->is_intersect = 0;
	node->med = 0;
	return (node);
}

/*
** to add path in a list of paths - back
*/

void		path_push_back(t_path **head, t_rconn *rconn)
{
	t_path	*node;

	if (!*head)
		*head = path_create_elem(rconn);
	else
	{
		node = *head;
		while (node->next)
			node = node->next;
		node->next = path_create_elem(rconn);
		if (node->next)
			node->next->prev = node;
	}
}

/*
** to get room list from path
*/

t_rconn		*path_get_room_lst(t_path *path_head)
{
	t_rconn	*roomlst;
	t_room	*room;
	t_rconn	*conn;

	roomlst = 0;
	while (path_head)
	{
		conn = path_head->lnks;
		while (conn)
		{
			room = room_find_by_room(roomlst, conn->room);
			if (!room && conn->room)
				conn_push_back(&roomlst, conn->room, 1);
			conn = conn->next;
		}
		path_head = path_head->next;
	}
	return (roomlst);
}

/*
** to get last path in ths paths list
*/

t_path		*path_get_last_elem(t_path *head)
{
	t_path	*node;

	node = head;
	while (node->next)
		node = node->next;
	return (node);
}
