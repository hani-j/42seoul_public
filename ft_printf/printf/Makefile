# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 17:30:06 by hjeong            #+#    #+#              #
#    Updated: 2022/04/28 21:29:54 by hjeong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Werror -Wall -Wextra

NAME = libftprintf.a
SRCS = ft_printf.c \
		ft_printf_char.c \
		ft_printf_hex.c \
		ft_printf_dni.c \
		ft_printf_u.c \
		ft_printf_utils.c 
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
