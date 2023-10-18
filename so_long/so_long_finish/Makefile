# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 10:58:57 by hjeong            #+#    #+#              #
#    Updated: 2022/07/11 09:47:06 by hjeong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wall -Wextra
NAME = so_long

SRCS = so_long.c \
		map.c \
		image_init.c \
		key.c \
		split.c \
		utils.c \
		utils2.c \
		get_next_line.c \
		get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework Appkit -o $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re
