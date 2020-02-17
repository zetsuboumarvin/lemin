/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_conn_ins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 11:51:02 by jflorent          #+#    #+#             */
/*   Updated: 2020/01/03 15:23:33 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ins_in_lnks(t_room *l_room, t_room *room, int weight)
{
	t_rconn		*new_conn;
	t_rconn		*prev;

	new_conn = conn_create_elem(room, weight);
	prev = l_room->lnks;
	while (prev && prev->next)
		prev = prev->next;
	if (!prev)
		l_room->lnks = new_conn;
	else
		prev->next = new_conn;
}
