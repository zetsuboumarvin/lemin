/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:35:55 by clianne           #+#    #+#             */
/*   Updated: 2019/09/04 18:21:48 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len;
	size_t	len_2;

	len = ft_strlen((char *)s1) + 1;
	len_2 = ft_strlen((char *)s2) + 1;
	if (len > len_2)
		len = len_2;
	if (len > n)
		len = n;
	return (ft_memcmp(s1, s2, len));
}
