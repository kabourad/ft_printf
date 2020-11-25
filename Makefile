# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/12 13:40:04 by kabourad          #+#    #+#              #
#    Updated: 2020/03/09 23:26:50 by kabourad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a
SRCS =	ft_printf.c	\
		check_zero_n_print.c	\
		ft_handler.c	\
		ft_putchar_ret.c	\
		ft_save.c \
		ft_treat_c.c \
		ft_treat_u.c \
		ft_treat_p.c \
		ft_treat_d.c \
		ft_treat_x.c \
		ft_treat_perc.c \
		ft_treat_xmaj.c \
		ft_treat_s.c \
		ft_treat_error.c \
		ft_treat_c_tools.c \
		ft_treat_x_tools.c \
		ft_treat_u_tools.c \
		ft_treat_p_tools.c \
		ft_treat_num_tools.c \
		ft_treat_s_tools.c \
		ft_utoa.c \
		ft_handler.c \
		ft_ulltoa_base.c \
		ft_utoa_base.c \
		ft_utoamaj_base.c \

OBJ =	$(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra
CC = gcc
INCLUDES = ./

.PHONY: clean fclean all re

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	ar rc $(NAME) $(OBJ) libft/*.o
	@ranlib $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -I/$(INCLUDES) -c $< -o $@

clean:
	make -C libft  fclean
	rm -f *.o

fclean: clean
	make -C libft  fclean
	rm -f $(NAME)

re: fclean all
