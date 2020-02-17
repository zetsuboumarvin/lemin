/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:16:21 by clianne           #+#    #+#             */
/*   Updated: 2019/09/06 15:29:09 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	dst_length;
	size_t	index;

	dst_length = 0;
	while (s1[dst_length] != '\0')
		dst_length++;
	index = 0;
	while (s2[index] != '\0' && index < n)
	{
		s1[dst_length] = s2[index];
		index++;
		dst_length++;
	}
	s1[dst_length] = '\0';
	return (s1);
}
