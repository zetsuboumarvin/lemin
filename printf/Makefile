# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clianne <clianne@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/17 12:17:02 by jflorent          #+#    #+#              #
#    Updated: 2019/11/22 00:10:57 by clianne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
MAKE = make
LIBDIR = libft/
FLAGS = -Wall -Wextra
SRCS = do_c_option.c do_p_option.c ft_itoa_base.c ft_printf.c parser.c \
		check_options.c do_f_option.c do_print_utils.c ft_math.c \
		do_s_option.c ft_litoa_base.c do_nprints.c arg_and_opt_lists.c \
		do_b_option.c do_int_option.c do_get_snum.c color.c get_next_line.c \
		ft_ulitoa_base.c la_create.c la_sub.c la_mult.c la_div.c \
		do_e_option.c la_round.c la_cmp.c do_iarray.c float_parse.c \
		do_file_option.c rounding.c la_reverse.c la_add.c do_g_option.c \
		do_date_option.c ft_putstrn.c do_f_decimal_print.c la_print.c \
		double_parse.c double_parse_add.c nan_and_inf.c la_count.c \
		la_reverse.c la_copy.c spec_c.c do_oxx_option.c do_toptions.c \
		nan_and_inf_add.c do_e_option_shift.c do_check_soption.c \
		arg_and_opt_lists_add.c ft_printf_add.c do_iarray_sort.c
SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	ft_strrchr.c ft_strqchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_toupper.c ft_tolower.c \
	ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
	ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
	ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
	ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	ft_lstmap.c \
	ft_sqrt.c ft_factorial.c ft_power.c ft_abs.c ft_isspace.c
OBJS = $(SRCS:.c=.o)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIB):
	cd $(LIBDIR) && $(MAKE)



%.o: %.c
	gcc -c $(FLAGS) $<

%.o: $(LIBDIR)%.c
	gcc -c $(FLAGS) $<

$(NAME): $(OBJS) $(OBJ)
	ar rc $@ $^

clean:
	rm -f $(OBJS) $(OBJ)
	cd $(LIBDIR) && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
