/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_ant_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:50:09 by jflorent          #+#    #+#             */
/*   Updated: 2020/01/07 19:29:44 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			run(t_rconn *start, t_rconn *next, int st, int print)
{
	if (next->room->room_type == 1 && start->room->ant > 0)
	{
		start->room->ant -= 1;
		next->room->ant += 1;
		next->room->ant_num = start->room->ant_num;
		if (print)
			ft_printf("L%d-%s ", start->room->ant_num, next->room->room_name);
		return ;
	}
	else if (next->room->room_type == 1 && start->room->ant == 0)
		return ;
	if (next->next->room->room_type != -2)
		run(next, next->next, st, print);
	else
		run(next, next->next->next, st, print);
	if (start->room->room_type == 0 && !st)
		return ;
	else if (start->room->ant > 0)
	{
		start->room->ant -= 1;
		next->room->ant += 1;
		next->room->ant_num = start->room->ant_num;
		if (print)
			ft_printf("L%d-%s ", start->room->ant_num, next->room->room_name);
	}
}

static void			algo_run(t_room *start, t_path *top, int print, int num)
{
	static int	number;
	int			st;

	if (num == 0)
	{
		number = 0;
		return ;
	}
	while (top)
	{
		if (start->ant > top->med || (top->prev == 0 && start->ant == 1))
		{
			st = 1;
			start->ant_num = ++number;
		}
		else
			st = 0;
		if (top->lnks->next->room->room_type != -2)
			run(top->lnks, top->lnks->next, st, print);
		else
			run(top->lnks, top->lnks->next->next, st, print);
		top = top->next;
	}
	if (print)
		ft_putchar('\n');
}

int					check_effect(t_path **sol, t_room **map, int print)
{
	int			start_count;
	t_room		*end;
	t_room		*start;
	int			count;

	count = 0;
	path_sort_by_length(sol);
	start = find_node(map, 0);
	end = find_node(map, 1);
	start_count = start->ant;
	while (end->ant != start_count)
	{
		algo_run(start, *sol, print, 1);
		count++;
	}
	algo_run(0, 0, 0, 0);
	start->ant = start_count;
	end->ant = 0;
	return (count);
}
