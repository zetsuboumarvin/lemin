/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:20:23 by clianne           #+#    #+#             */
/*   Updated: 2019/09/05 11:25:39 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*v;
	size_t	index;

	if (!(v = malloc(size)))
		return (NULL);
	index = 0;
	while (index < size)
	{
		v[index] = 0;
		index++;
	}
	return (v);
}
