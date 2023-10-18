CC = c++
CFLAGS = -Werror -Wall -Wextra -std=c++98
NAME = animal

SRCS = main.cpp \
		Animal.cpp \
		Brain.cpp \
		Cat.cpp \
		Dog.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : 
	make fclean 
	make all	

.PHONY : all clean fclean re