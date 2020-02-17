/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:36:21 by clianne           #+#    #+#             */
/*   Updated: 2019/09/05 21:36:01 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	char			*src_str;
	unsigned int	index;

	if (!s || !f)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!new_str)
		return (NULL);
	src_str = (char *)s;
	index = 0;
	while (src_str[index] != '\0')
	{
		new_str[index] = f(index, src_str[index]);
		index++;
	}
	new_str[index] = '\0';
	return (new_str);
}
