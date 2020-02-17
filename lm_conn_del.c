/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_conn_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 07:54:49 by clianne           #+#    #+#             */
/*   Updated: 2020/01/04 13:03:04 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** to del room connection list and NULL memory
*/

void		conn_lst_del(t_rconn **rconn)
{
	t_rconn	*node;
	t_rconn	*buf;

	if (!*rconn)
		return ;
	node = *rconn;
	while (node)
	{
		buf = node->next;
		free(node);
		node = NULL;
		node = buf;
	}
	*rconn = NULL;
}

/*
** to del first element from rooms connection list
*/

void		conn_del_front(t_rconn **head)
{
	t_rconn	*node;

	if (!*head)
		return ;
	else
	{
		node = (*head)->next;
		if (node)
			node->prev = 0;
		free(*head);
		*head = node;
	}
}
