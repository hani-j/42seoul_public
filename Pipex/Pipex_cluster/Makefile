CC = cc
CFLAGS = -Werror -Wall -Wextra
NAME = pipex
BONUS = pipex_bonus

SRCS = pipex.c \
		utils.c \
		split.c 
OBJS = $(SRCS:.c=.o)

SRCS_B = pipex_bonus.c \
		process_bonus.c \
		utils.c \
		split.c \
		get_next_line.c \
		get_next_line_utils.c
OBJS_B = $(SRCS_B:.c=.o)

ifdef WITH_BONUS
	NAME = $(BONUS)
	OBJECTS = $(OBJS_B)
else
	OBJECTS = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

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
