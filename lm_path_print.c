/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_path_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:29:40 by clianne           #+#    #+#             */
/*   Updated: 2020/01/07 17:46:00 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** to print single path
*/

void				path_print(t_rconn *lnks, size_t options,
	size_t idx, int len)
{
	t_rconn		*top;

	top = lnks;
	ft_printf("path #%u, name - %s, QofN = %d\n", idx,
		lnks->next->room->room_name, len);
	if (options)
		while (top)
		{
			ft_printf("%s(%d) -> ", top->room->room_name, top->room->room_type);
			top = top->next;
		}
	ft_putchar('\n');
}

/*
** to print list of paths
*/

void				path_lst_print(t_path *sol, size_t options)
{
	t_rconn		*top;
	t_path		*solut;
	size_t		idx;

	solut = sol;
	idx = 0;
	while (solut)
	{
		idx++;
		top = solut->lnks;
		path_print(top, options, idx, solut->length);
		solut = solut->next;
	}
}
