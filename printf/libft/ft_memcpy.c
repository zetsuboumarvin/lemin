/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:50:59 by clianne           #+#    #+#             */
/*   Updated: 2019/09/06 15:43:58 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s_dst;
	unsigned char	*s_src;

	if (n == 0 || src == dst)
		return (dst);
	s_dst = (unsigned char *)dst;
	s_src = (unsigned char *)src;
	while (--n)
		*s_dst++ = *s_src++;
	*s_dst = *s_src;
	return (dst);
}
