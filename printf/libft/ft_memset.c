/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:01:28 by clianne           #+#    #+#             */
/*   Updated: 2019/11/04 03:48:21 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*buf;

	if (len == 0)
		return (b);
	buf = (unsigned char *)b;
	while (len--)
		*buf++ = (unsigned char)c;
	return (b);
}
