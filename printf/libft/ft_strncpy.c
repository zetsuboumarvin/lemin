/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:49:20 by clianne           #+#    #+#             */
/*   Updated: 2019/09/06 15:29:47 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	index;

	index = 0;
	while ((src[index] != '\0') && (index < len))
	{
		dst[index] = src[index];
		index++;
	}
	while (index < len)
	{
		dst[index] = '\0';
		index++;
	}
	return (dst);
}
