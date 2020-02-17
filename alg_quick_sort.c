/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_quick_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:53:39 by clianne           #+#    #+#             */
/*   Updated: 2019/12/30 08:10:31 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** to quick sort of a double-link list
*/

static void	do_swap(t_path *from, t_path *to)
{
	t_path	buff;

	buff.length = from->length;
	buff.med = from->med;
	buff.lnks = from->lnks;
	from->length = to->length;
	from->med = to->med;
	from->lnks = to->lnks;
	to->length = buff.length;
	to->med = buff.med;
	to->lnks = buff.lnks;
}

void		do_alg_quick_sort(t_path *left, t_path *right)
{
	t_path	*start;
	t_path	*current;
	t_path	*old_current;

	if (left == right)
		return ;
	start = left;
	current = start->next;
	while (1)
	{
		if (start->length < current->length)
			do_swap(start, current);
		if (current == right)
			break ;
		current = current->next;
	}
	do_swap(left, current);
	old_current = current;
	current = current->prev;
	if (current && left->prev != current && current->next != left)
		do_alg_quick_sort(left, current);
	current = old_current;
	current = current->next;
	if (current && current->prev != right && right->next != current)
		do_alg_quick_sort(current, right);
}
