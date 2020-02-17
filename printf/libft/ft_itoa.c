/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:29:28 by clianne           #+#    #+#             */
/*   Updated: 2019/09/06 13:08:19 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*is_neg_max_int(void)
{
	char *res;

	res = ft_strnew(11);
	if (res)
		res = ft_strcpy(res, "-2147483648");
	return (res);
}

static char		*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = (int)(ft_strlen(str) - 1);
	if (str[0] == '-')
		i++;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);
}

static size_t	get_str_size(int n)
{
	size_t index;

	index = 0;
	if (n < 0)
		index++;
	while (n != 0)
	{
		index++;
		n /= 10;
	}
	return (index);
}

static char		*get_string(char *res, int n)
{
	int index;

	index = 0;
	if (n < 0)
	{
		res[index] = '-';
		n *= -1;
		index++;
	}
	while (n != 0)
	{
		res[index] = (char)(n % 10 + '0');
		index++;
		n /= 10;
	}
	res[index] = '\0';
	res = ft_strrev(res);
	return (res);
}

char			*ft_itoa(int n)
{
	char *res;

	if (n == 0)
	{
		res = ft_strnew(1);
		if (res)
			res = ft_strcpy(res, "0");
		return (res);
	}
	else if (n == -2147483648)
		return (is_neg_max_int());
	else
	{
		res = ft_strnew(get_str_size(n));
		if (!res)
			return (NULL);
		res = get_string(res, n);
		return (res);
	}
}
