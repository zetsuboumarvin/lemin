/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_map_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:25:22 by clianne           #+#    #+#             */
/*   Updated: 2020/01/08 12:33:44 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "lemin.h"

/*
** to return code
*/

static int		map_ret_error(char **line)
{
	str_print_and_del(line);
	return (0);
}

/*
** to create connection between rooms
*/

static size_t	room_or_tube_create(t_room **map, char *line, int *room_type)
{
	if (ft_strqchr(line, ' ') == 2)
	{
		if (!room_create(map, line, room_type))
			return (0);
	}
	else if (ft_strqchr(line, '-') == 1)
	{
		if (!tube_create(map, line))
			return (0);
	}
	return (1);
}

/*
** to save qty of ants for map
*/

void			ant_save(t_room *head, int q_ant)
{
	t_room	*node;

	node = head;
	while (node)
	{
		if (node->room_type == 0)
		{
			node->ant = q_ant;
			break ;
		}
		node = node->next;
	}
}

/*
** to read map from file
*/

void			str_print_and_del(char **s)
{
	ft_printf("%s\n", *s);
	ft_strdel(s);
}

int				map_read(t_room **map)
{
	char	*line;
	int		room_type;
	int		q_ant;

	q_ant = -1;
	room_type = -1;
	line = 0;
	while ((get_next_line(0, &line)) > 0 && line)
	{
		if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
			room_type = !ft_strcmp(line, "##start") ? 0 : 1;
		else if (ft_strqchr(line, ' ') == 2 || ft_strqchr(line, '-') == 1)
		{
			if (!room_or_tube_create(map, line, &room_type))
				return (map_ret_error(&line));
		}
		else if (q_ant == -1 && ft_isint(line))
			q_ant = ft_atoi(line);
		else if (line[0] != '#')
			return (map_ret_error(&line));
		str_print_and_del(&line);
	}
	if (q_ant > 0)
		ant_save(*map, q_ant);
	return (map_validation(*map));
}
