/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:20:25 by clianne           #+#    #+#             */
/*   Updated: 2019/09/06 16:06:39 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s_dst;
	unsigned char	*s_src;
	size_t			index;

	s_dst = (unsigned char *)dst;
	s_src = (unsigned char *)src;
	index = 0;
	while (index < n)
	{
		s_dst[index] = s_src[index];
		if (s_src[index] == (unsigned char)c)
			return (s_dst + index + 1);
		index++;
	}
	return (NULL);
}
