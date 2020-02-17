# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 05:29:44 by clianne           #+#    #+#              #
#    Updated: 2020/01/08 11:45:20 by jflorent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
MAKE = make
LIB = printf/libftprintf.a
LIBDIR = printf/
FLAGS = -Wall -Wextra -Werror

SRCS = main.c lm_map.c lm_map_read.c lm_list.c lm_room.c lm_conn_ins.c \
		lm_tube.c lm_conn.c lm_conn_del.c \
		lm_path_list.c lm_path_list_del.c lm_path_utils.c lm_path_intersect.c \
		lm_path_print.c common_func.c lm_ant_run.c \
		ft_isint.c alg_bford.c lm_suurballe.c \
		alg_quick_sort.c alg_dijkstra.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIB):
	cd $(LIBDIR) && $(MAKE)

%.o: %.c $(LIB)
	gcc -c $(FLAGS) $<

$(NAME): $(OBJS)
	gcc $(FLAGS) $^ -L$(LIBDIR) -lftprintf -o $@

clean:
	rm -f $(OBJS)
	cd $(LIBDIR) && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
