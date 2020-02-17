/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:56:21 by clianne           #+#    #+#             */
/*   Updated: 2019/09/06 23:26:16 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int		is_ws(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' ||
		c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int				ft_atoi(const char *str)
{
	int			n;
	int			flag;
	long long	check;

	n = 0;
	flag = 1;
	check = 0;
	while (*str && is_ws(*str))
		str++;
	if (*str == '-')
		flag = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if ((check > (check * 10 + flag * (*str - '0'))) && flag == 1)
			return (-1);
		if ((check < (check * 10 + flag * (*str - '0'))) && flag == -1)
			return (0);
		n = 10 * n + (*str - '0');
		check = check * 10 + flag * (*str - '0');
		str++;
	}
	return (n * flag);
}
