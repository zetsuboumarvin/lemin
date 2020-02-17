/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:33:53 by clianne           #+#    #+#             */
/*   Updated: 2019/09/05 22:06:34 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int len;
	int	len_2;

	len = ft_strlen((char *)s1) + 1;
	len_2 = ft_strlen((char *)s2) + 1;
	if (len_2 < len)
		len = len_2;
	return (ft_memcmp(s1, s2, len));
}
