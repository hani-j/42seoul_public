# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 08:05:48 by hjeong            #+#    #+#              #
#    Updated: 2022/08/01 08:05:49 by hjeong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minitalk
SERVER			= server
CLIENT			= client
LIBFT			= libft.a

SERVER_SRC			= server.c
SERVER_OBJ			= server.o
SERVER_BONUS_SRC	= server_bonus.c
SERVER_BONUS_OBJ	= server_bonus.o
CLIENT_SRC			= client.c
CLIENT_OBJ			= client.o
CLIENT_BONUS_SRC	= client_bonus.c
CLIENT_BONUS_OBJ	= client_bonus.o

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

ifdef WITH_BONUS
	C_OBJECT = $(CLIENT_BONUS_OBJ)
	S_OBJECT = $(SERVER_BONUS_OBJ)
	SERVER = server_bonus
	CLIENT = client_bonus
else
	C_OBJECT = $(CLIENT_OBJ)
	S_OBJECT = $(SERVER_OBJ)
endif

.o : .c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME) 

$(NAME) : $(SERVER) $(CLIENT) 

bonus : 
	make WITH_BONUS=1 all

$(SERVER) : $(S_OBJECT) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(CLIENT) : $(C_OBJECT) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBFT) :
	make -C libft
	cp libft/libft.a .

clean :
	rm -rf $(SERVER_OBJ) $(CLIENT_OBJ) $(SERVER_BONUS_OBJ) $(CLIENT_BONUS_OBJ)
	make -C libft clean

fclean : clean
	rm -rf server server_bonus client client_bonus libft.a
	make -C libft fclean

re :
	make fclean
	make all
