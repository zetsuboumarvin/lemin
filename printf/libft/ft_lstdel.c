/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:16:47 by clianne           #+#    #+#             */
/*   Updated: 2019/09/06 12:21:49 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*buf;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		buf = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = buf;
	}
	*alst = NULL;
}
