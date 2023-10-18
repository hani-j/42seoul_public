# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 10:58:57 by hjeong            #+#    #+#              #
#    Updated: 2022/07/09 18:36:06 by hjeong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wall -Wextra
NAME = so_long
BONUS = 

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

SRCS_B = 
OBJS_B = $(SRCS_B:.c=.o)

ifdef WITH_BONUS
	NAME = $(BONUS)
	OBJECTS = $(OBJS_B)
else
	OBJECTS = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework Appkit -o $@ $^

bonus :
	make WITH_BONUS=1 all

clean :
	rm -f $(OBJS) $(OBJS_B)

fclean : clean
	rm -f $(NAME) $(BONUS)

re : 
	make fclean 
	make all	

.PHONY : all clean fclean re bonus
