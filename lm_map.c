/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:39:25 by clianne           #+#    #+#             */
/*   Updated: 2020/01/08 11:49:04 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "lemin.h"

/*
** to del map object and NULL memory
*/

void		map_del(t_room **map)
{
	t_room	*node;
	t_room	*buf;

	if (!*map)
		return ;
	node = *map;
	while (node)
	{
		buf = node->next;
		conn_lst_del(&(node->lnks));
		ft_strdel(&node->room_name);
		node->lnks = 0;
		free(node);
		node = NULL;
		node = buf;
	}
	*map = NULL;
}

/*
** to free map: file descriptor and other structures
*/

void		map_free(t_room **map)
{
	map_del(map);
}

/*
** map validation:
*/

int			map_validation(t_room *head)
{
	t_room	*node;
	t_room	*double_node;

	if (!head || !find_node(&head, 0) || !find_node(&head, 1) ||
		find_node(&head, 0)->ant <= 0)
		return (0);
	node = head;
	while (node)
	{
		if (node->room_type < -1 || node->room_type > 1)
			return (0);
		if (node->room_type >= 0 && !node->lnks)
			return (0);
		double_node = node->next;
		while (double_node)
		{
			if (node->room_name == double_node->room_name ||
			(node->room_type >= 0 && node->room_type == double_node->room_type))
				return (0);
			double_node = double_node->next;
		}
		node = node->next;
	}
	return (1);
}

/*
** to check for correct x, y
*/

size_t		room_check_xy(char **els)
{
	size_t	idx;

	if (!els)
		return (0);
	idx = 0;
	while (els[idx])
	{
		if ((idx == 1 || idx == 2) && !ft_isint(els[idx]))
			return (0);
		idx++;
	}
	return (1);
}
