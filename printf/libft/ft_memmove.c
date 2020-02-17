/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 19:06:12 by clianne           #+#    #+#             */
/*   Updated: 2019/09/06 15:42:12 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s_src;
	unsigned char	*s_dst;

	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		if (len == 0 || src == dst)
			return (dst);
		s_src = (unsigned char *)src;
		s_dst = (unsigned char *)dst;
		while (len--)
			s_dst[len] = s_src[len];
	}
	return (dst);
}
