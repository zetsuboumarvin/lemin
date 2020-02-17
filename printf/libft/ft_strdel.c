/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:55:42 by clianne           #+#    #+#             */
/*   Updated: 2019/11/21 14:22:28 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_strdel(char **as)
{
	if (as && *as)
		ft_memdel((void **)as);
}

void	ft_strlist_del(char **words)
{
	int	index;

	if (!words)
		return ;
	index = 0;
	while (words[index])
	{
		free(words[index]);
		words[index] = NULL;
		index++;
	}
	free(words);
	words = NULL;
}
