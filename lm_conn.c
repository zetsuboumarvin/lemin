/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_conn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:31:05 by clianne           #+#    #+#             */
/*   Updated: 2020/01/07 17:48:08 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** to create connection for map in a list of connections
*/

t_rconn		*conn_create_elem(t_room *room, int weight)
{
	t_rconn	*node;

	if (!(node = (t_rconn *)malloc(sizeof(t_rconn))))
		return (0);
	if (!room)
		node->room = room;
	node->room = room;
	node->dest = 0;
	node->weight = weight;
	node->prev = 0;
	node->next = 0;
	return (node);
}

/*
** to add connection for map in a list of connections - back
*/

void		conn_push_back(t_rconn **head, t_room *rconn, int weight)
{
	t_rconn	*node;

	if (!*head)
		*head = conn_create_elem(rconn, weight);
	else
	{
		node = *head;
		while (node->next)
			node = node->next;
		node->next = conn_create_elem(rconn, weight);
		if (node->next)
			node->next->prev = node;
	}
}

/*
** to add connection for map in a list of connections - front
*/

void		conn_push_front(t_rconn **head, t_room *rconn, int weight)
{
	t_rconn	*node;

	if (!*head)
		*head = conn_create_elem(rconn, weight);
	else
	{
		node = conn_create_elem(rconn, weight);
		node->next = *head;
		(*head)->prev = node;
		*head = node;
	}
}

/*
** to del lnk to room from lnks
*/

void		conn_do_del25lines(t_rconn *before, t_rconn *next,
	t_room *node)
{
	if (before)
	{
		before->next = next;
		if (next)
			next->prev = before;
	}
	else
	{
		node->lnks = next;
		if (node->lnks)
			(node->lnks)->prev = 0;
	}
}

void		conn_del_room_from_lnks(t_room *l_room, t_room *room)
{
	t_rconn	*rconn;
	t_rconn	*before;
	t_rconn	*next;

	before = 0;
	if (!(l_room->lnks))
		return ;
	rconn = l_room->lnks;
	next = rconn->next;
	while (rconn)
	{
		if (rconn->room == room)
		{
			free(rconn);
			rconn = 0;
			conn_do_del25lines(before, next, l_room);
			break ;
		}
		before = rconn;
		rconn = rconn->next;
		if (rconn)
			next = rconn->next;
	}
}
