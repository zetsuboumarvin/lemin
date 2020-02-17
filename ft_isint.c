/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 23:09:19 by clianne           #+#    #+#             */
/*   Updated: 2019/11/21 23:10:50 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** to check if number in string is between MIN_INT and MAX_INT
*/

size_t	ft_isint(char *s)
{
	int		a;
	char	*s1;
	int		res;

	a = ft_atoi(s);
	s1 = ft_itoa(a);
	res = (!ft_strcmp(s, s1) ? 1 : 0);
	ft_strdel(&s1);
	return (res);
}
