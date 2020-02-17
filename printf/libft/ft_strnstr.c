/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:48:48 by clianne           #+#    #+#             */
/*   Updated: 2019/09/06 15:26:38 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_2;

	if (*needle == '\0')
		return ((char *)haystack);
	len_2 = ft_strlen((char *)needle);
	while (*haystack != '\0' && len-- >= len_2)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, len_2) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
