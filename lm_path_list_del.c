/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_path_list_del.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 08:27:00 by clianne           #+#    #+#             */
/*   Updated: 2019/12/30 08:09:04 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** to del paths list and NULL memory
*/

void		path_lst_del(t_path **head_path, size_t is_rconn_del)
{
	t_path	*node;
	t_path	*buf;

	if (!*head_path)
		return ;
	node = *head_path;
	while (node)
	{
		buf = node->next;
		if (is_rconn_del)
			conn_lst_del(&(node->lnks));
		free(node);
		node = NULL;
		node = buf;
	}
	*head_path = NULL;
}

/*
** to drop path from paths lst
*/

void		path_drop(t_path **head_path, t_path *to_del)
{
	t_path	*node;
	t_path	*buf;

	node = *head_path;
	while (node)
	{
		if (node == to_del)
		{
			buf = (node)->next;
			if (buf)
				buf->prev = node->prev;
			if (node == *head_path)
				*head_path = buf;
			else
			{
				if (buf)
					buf->prev->next = buf;
				else
					node->prev->next = 0;
			}
			free(node);
			break ;
		}
		node = node->next;
	}
}

/*
** to del path element and free memory
*/

void		path_single_del(t_path **head_path, t_path *to_del)
{
	t_path	*buf;

	if (!*head_path || !to_del)
		return ;
	buf = to_del->next;
	buf->prev = to_del->prev;
	if (to_del == *head_path)
		*head_path = buf;
	else
		to_del->prev->next = buf;
	free(to_del);
	to_del = 0;
}
