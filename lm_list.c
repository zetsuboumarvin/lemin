/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 23:22:16 by clianne           #+#    #+#             */
/*   Updated: 2020/01/08 11:47:25 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

/*
** to create element for stack
*/

static void		map_elem_fill(t_room *node)
{
	node->room_name = 0;
	node->lnks = 0;
	node->x = 0;
	node->y = 0;
	node->room_type = -1;
	node->split = 0;
	node->split_room = 0;
	node->ant = 0;
	node->weight = 0;
	node->visited = 0;
	node->anc = 0;
	node->next = 0;
	node->prev = 0;
	node->inp_anc = 0;
	node->out_anc = 0;
}

t_room			*map_create_elem(char **els, int room_type)
{
	t_room	*node;

	if (!(node = (t_room *)malloc(sizeof(t_room))))
		return (0);
	map_elem_fill(node);
	node->room_type = room_type;
	node->weight = (room_type == 0) ? 0 : LM_MAX;
	node->inp_weight = LM_MAX;
	node->out_weight = LM_MAX;
	node->room_name = ft_strdup(els[0]);
	if (room_type != -2)
	{
		node->x = (els[1]) ? ft_atoi(els[1]) : 0;
		node->y = (els[2]) ? ft_atoi(els[2]) : 0;
	}
	node->next = NULL;
	return (node);
}

/*
** to add element to end of map list
*/

t_room			*map_push_back(t_room **head, char **els, int room_type)
{
	t_room	*node;

	if (!*head)
	{
		*head = map_create_elem(els, room_type);
		return (*head);
	}
	else
	{
		node = *head;
		while (node->next)
			node = node->next;
		node->next = map_create_elem(els, room_type);
		if (node->next)
			node->next->prev = node;
	}
	return (node->next);
}
