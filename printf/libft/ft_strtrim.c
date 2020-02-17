/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:13:16 by clianne           #+#    #+#             */
/*   Updated: 2019/09/06 17:31:16 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	size_t	ft_trim_str_len(char *s)
{
	size_t	index;
	size_t	q_spaces;
	size_t	len;

	len = ft_strlen(s);
	index = 0;
	while (s[index] == ' ' || s[index] == '\n' || s[index] == '\t')
		index++;
	q_spaces = index;
	if (s[index] != '\0')
	{
		index = len - 1;
		while (s[index] == ' ' || s[index] == '\n' || s[index] == '\t')
		{
			index--;
			q_spaces++;
		}
	}
	return (len - q_spaces);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	index;
	size_t	index_trim;
	size_t	trim_str_len;

	if (!s)
		return (NULL);
	trim_str_len = ft_trim_str_len((char *)s);
	str = (char *)malloc(sizeof(*str) * (trim_str_len + 1));
	if (!str)
		return (NULL);
	index = 0;
	while (s[index] == ' ' || s[index] == '\n' || s[index] == '\t')
		index++;
	index_trim = 0;
	while (index_trim < trim_str_len)
	{
		str[index_trim] = s[index];
		index_trim++;
		index++;
	}
	str[index_trim] = '\0';
	return (str);
}
