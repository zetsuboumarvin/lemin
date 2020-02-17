/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:30:28 by clianne           #+#    #+#             */
/*   Updated: 2019/09/05 21:11:54 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	int		index;

	if (!s || !f)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!new_str)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		new_str[index] = f(s[index]);
		index++;
	}
	new_str[index] = '\0';
	return (new_str);
}
