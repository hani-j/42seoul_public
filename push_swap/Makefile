CC = cc
CFLAGS = -Werror -Wall -Wextra
NAME = push_swap
BONUS = checker

SRCS = push_swap.c \
		ft_split.c \
		node_utils.c \
		stack_utils.c \
		stack_utils1.c \
		set_astack.c \
		sort_stack.c \
		morethan5.c
OBJS = $(SRCS:.c=.o)

SRCS_B = checker.c \
		ft_split.c \
		node_utils.c \
		stack_utils_b.c \
		stack_utils1_b.c \
		set_astack.c \
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
