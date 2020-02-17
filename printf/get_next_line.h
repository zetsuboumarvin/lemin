/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 11:48:17 by clianne           #+#    #+#             */
/*   Updated: 2019/09/13 17:20:49 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include "libft/libft.h"

# define BUFF_SIZE 4

typedef struct			s_fd_list
{
	char				*str;
	int					fd;
	struct s_fd_list	*next;
}						t_fd_list;

int						get_next_line(const int fd, char **line);

#endif
