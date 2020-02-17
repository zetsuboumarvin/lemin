/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_path_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 08:09:01 by clianne           #+#    #+#             */
/*   Updated: 2020/01/08 11:42:56 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** to sort conn nodes by length
*/

void		path_sort_by_length(t_path **path)
{
	t_path	*start_path;
	t_path	*end_path;

	if (!*path || !(*path)->next)
		return ;
	path_length_count(*path);
	start_path = *path;
	end_path = path_get_last_elem(*path);
	do_alg_quick_sort(start_path, end_path);
	path_calc_med(*path);
}

/*
** to copy path: del and copy src to dest paths
*/

t_path		*path_copy(t_path **src)
{
	t_path	*new_path;
	t_path	*node;

	if (!*src)
		return (0);
	new_path = 0;
	node = *src;
	while (node)
	{
		path_push_back(&new_path, node->lnks);
		node = node->next;
	}
	return (new_path);
}

/*
** to count len of paths
*/

void		path_length_count(t_path *path)
{
	t_path	*node;
	t_rconn	*rconn;

	if (!path)
		return ;
	node = path;
	while (node)
	{
		node->length = 0;
		rconn = node->lnks;
		while (rconn)
		{
			if (rconn->room->room_type != -2 || (rconn->room->room_type == -2 &&
			!((rconn->next && rconn->next->room->split_room == rconn->room) ||
			(rconn->prev && rconn->prev->room->split_room == rconn->room))))
				node->length++;
			rconn = rconn->next;
		}
		node = node->next;
	}
}

/*
** to get path with min length
*/

t_path		*path_get_min_length(t_path *head)
{
	t_path	*min;

	if (!head)
		return (NULL);
	min = head;
	while (head)
	{
		if (head->length < min->length)
			min = head;
		head = head->next;
	}
	return (min);
}

/*
** to calculate med for paths
*/

void		path_calc_med(t_path *head)
{
	t_path	*node_1;
	t_path	*node_2;
	int		med;

	if (!head)
		return ;
	node_1 = head;
	while (node_1)
	{
		med = 0;
		node_2 = head;
		while (node_2 != node_1)
		{
			med += node_1->length - node_2->length;
			node_2 = node_2->next;
		}
		node_1->med = med;
		node_1 = node_1->next;
	}
}
