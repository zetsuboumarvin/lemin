/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:31:45 by clianne           #+#    #+#             */
/*   Updated: 2019/09/06 12:42:51 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res_list;
	t_list	*buf;

	if (!lst || !f)
		return (NULL);
	if (!(buf = f(lst)))
		return (NULL);
	res_list = buf;
	while (lst->next)
	{
		lst = lst->next;
		if (!(buf->next = f(lst)))
		{
			free(buf->next);
			return (NULL);
		}
		buf = buf->next;
	}
	return (res_list);
}
