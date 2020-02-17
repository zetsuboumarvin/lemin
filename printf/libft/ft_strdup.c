/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:36:08 by clianne           #+#    #+#             */
/*   Updated: 2019/09/06 15:29:25 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;

	if (!(dest = (char*)malloc(sizeof(char) * (ft_strlen((char *)s1) + 1))))
		return (NULL);
	return (ft_strcpy(dest, s1));
}
