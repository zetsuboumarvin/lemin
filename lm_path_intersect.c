/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_path_intersect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 08:17:28 by clianne           #+#    #+#             */
/*   Updated: 2020/01/07 17:44:43 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** to swap intersection rib
*/

static void		do_buf_del(t_rconn *buf_to_del[2][2])
{
	buf_to_del[0][1]->next = 0;
	buf_to_del[1][1]->next = 0;
	conn_lst_del(&buf_to_del[0][0]);
	conn_lst_del(&buf_to_del[1][0]);
}

void			path_swap(t_rconn *lnks_1, t_rconn *lnks_2)
{
	t_rconn	*start[2];
	t_rconn	*finish[2];
	t_rconn	*buf_to_del[2][2];

	start[0] = lnks_1;
	finish[0] = lnks_1;
	start[1] = lnks_2;
	finish[1] = lnks_2;
	buf_to_del[0][0] = lnks_1->next;
	buf_to_del[1][1] = lnks_2;
	while (finish[0]->next && start[1]->prev &&
		finish[0]->next->room == start[1]->prev->room)
	{
		finish[0] = finish[0]->next;
		start[1] = start[1]->prev;
	}
	buf_to_del[0][1] = finish[0];
	buf_to_del[1][0] = start[1]->next;
	lnks_1->next = lnks_2->next;
	if (lnks_1->next)
		lnks_1->next->prev = lnks_1;
	start[1]->next = finish[0]->next;
	if (start[1]->next)
		start[1]->next->prev = start[1];
	do_buf_del(buf_to_del);
}

/*
** to check intersection between 2 paths
*/

size_t			path_check_intersection(t_rconn *lnks_1, t_rconn *lnks_2)
{
	t_room	*room[2][2];
	t_rconn	*pt2;
	size_t	ret;

	ret = 0;
	while (lnks_1 && lnks_1->next)
	{
		room[0][0] = lnks_1->room;
		room[0][1] = lnks_1->next->room;
		pt2 = lnks_2;
		while (pt2 && pt2->next)
		{
			room[1][0] = pt2->room;
			room[1][1] = pt2->next->room;
			if (room[0][1] == room[1][0] && room[0][0] == room[1][1])
			{
				path_swap(lnks_1, pt2->next);
				room[0][1] = lnks_1->next->room;
				ret = 1;
			}
			pt2 = pt2->next;
		}
		lnks_1 = lnks_1->next;
	}
	return (ret);
}

/*
** to delete paths with intersections
*/

void			path_del_intersection(t_path **path_head)
{
	t_path	*node;
	t_path	*buf;

	node = *path_head;
	while (node)
	{
		if (node->is_intersect)
		{
			buf = node->next;
			if (*path_head && node)
				path_drop(path_head, node);
			node = buf;
		}
		else
			node = node->next;
	}
}

/*
** intersection: check, del, search and create new path
*/

void			path_oper_intersection(t_path **path_head, t_rconn *result)
{
	t_path	*node[2];

	path_push_back(path_head, result);
	path_length_count(*path_head);
	node[0] = *path_head;
	while (node[0])
	{
		node[1] = node[0]->next;
		while (node[1])
		{
			if (path_check_intersection(node[0]->lnks, node[1]->lnks))
			{
				path_length_count(*path_head);
				node[0]->is_intersect++;
				node[1]->is_intersect++;
				node[1] = node[0]->next;
			}
			else
				node[1] = node[1]->next;
		}
		node[0] = node[0]->next;
	}
}
