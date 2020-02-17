/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:10:39 by clianne           #+#    #+#             */
/*   Updated: 2019/09/06 15:29:01 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int dst_length;
	int index;

	dst_length = 0;
	while (s1[dst_length] != '\0')
		dst_length++;
	index = 0;
	while (s2[index] != '\0')
	{
		s1[dst_length] = s2[index];
		index++;
		dst_length++;
	}
	s1[dst_length] = '\0';
	return (s1);
}
