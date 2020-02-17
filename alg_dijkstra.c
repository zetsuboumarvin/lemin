/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_dijkstra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:34:07 by clianne           #+#    #+#             */
/*   Updated: 2020/01/03 14:00:34 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** to create new node for deck of rooms
*/

t_rdeck			*deck_create_elem(t_room *room)
{
	t_rdeck	*rdeck;

	if (!(rdeck = (t_rdeck *)malloc(sizeof(t_rdeck))))
		return (0);
	rdeck->room = room;
	rdeck->next = 0;
	return (rdeck);
}

/*
** to add element to the end of deck of rooms list
*/

void			deck_push_back(t_rdeck **head, t_room *room)
{
	t_rdeck	*node;

	if (!*head)
		*head = deck_create_elem(room);
	else
	{
		node = *head;
		while (node->next)
			node = node->next;
		node->next = deck_create_elem(room);
	}
}

/*
** to del first element from deck of rooms list
*/

void			deck_del_front(t_rdeck **head)
{
	t_rdeck	*node;

	if (!*head)
		return ;
	else
	{
		node = (*head)->next;
		free(*head);
		*head = node;
	}
}

/*
** to find shortest path
*/

static void		do_go_through_lnks(t_rconn **deck_head, t_room *node)
{
	t_rconn	*lnks;

	lnks = node->lnks;
	while (lnks)
	{
		if (!lnks->room->visited && lnks->room->weight > node->weight + 1)
		{
			lnks->room->weight = node->weight + 1;
			lnks->room->anc = node;
			conn_push_back(deck_head, lnks->room, 1);
		}
		lnks = lnks->next;
	}
	node->visited = 1;
}

t_rconn			*do_alg_dijkstra(t_room **map)
{
	t_rconn	*deck_head;
	t_room	*node;
	t_rconn	*path;

	deck_head = 0;
	node = find_node(map, 0);
	do_go_through_lnks(&deck_head, node);
	while (deck_head)
	{
		if (!deck_head->room->visited)
			do_go_through_lnks(&deck_head, deck_head->room);
		conn_del_front(&deck_head);
	}
	node = find_node(map, 1);
	path = 0;
	while (node)
	{
		conn_push_front(&path, node, 1);
		node = node->anc;
	}
	return (path);
}
