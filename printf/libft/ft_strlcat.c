/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 19:27:03 by clianne           #+#    #+#             */
/*   Updated: 2019/09/06 15:28:50 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	dst_length;
	size_t	src_length;

	dst_length = 0;
	while (dst[dst_length] != '\0' && dst_length < size)
		dst_length++;
	src_length = 0;
	while (src[src_length] != '\0')
		src_length++;
	index = 0;
	while ((src[index] != '\0') && ((index + dst_length + 1) < size))
	{
		dst[dst_length + index] = src[index];
		index++;
	}
	if (index + dst_length < size)
		dst[index + dst_length] = '\0';
	return (dst_length + src_length);
}
