/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_tube.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:25:00 by clianne           #+#    #+#             */
/*   Updated: 2020/01/04 12:37:30 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** to return with code
*/

static size_t	ret_tube_create(char **els, size_t code)
{
	ft_strlist_del(els);
	return (code);
}

/*
** to add room connection for map
*/

size_t			conn_add(t_room *rooms[2])
{
	conn_push_back(&(rooms[0]->lnks), rooms[1], 1);
	if (rooms[0] != rooms[1])
		conn_push_back(&(rooms[1]->lnks), rooms[0], 1);
	return (1);
}

/*
** to write tube for rooms
*/

size_t			tube_create(t_room **map, char *line)
{
	char	**els;
	t_room	*rooms[2];

	if (!line)
		return (0);
	els = ft_strsplit(line, '-');
	rooms[0] = room_find_by_name(*map, els[0]);
	rooms[1] = room_find_by_name(*map, els[1]);
	if (!rooms[0] || !rooms[1])
		return (ret_tube_create(els, 0));
	if (!conn_add(rooms))
		return (ret_tube_create(els, 0));
	return (ret_tube_create(els, 1));
}
