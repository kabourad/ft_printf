# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/12 13:40:04 by kabourad          #+#    #+#              #
#    Updated: 2020/01/12 15:18:39 by kabourad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a
SRCS =	ft_printf.c	\
		ft_save.c \
		ft_itoa_base.c \
		main.c \

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
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all
