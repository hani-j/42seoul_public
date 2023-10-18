CC = c++
CFLAGS = -Werror -Wall -Wextra -std=c++98
NAME = phonebook

SRCS = 	main.cpp \
		PhoneBook.cpp \
		Contact.cpp \

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : 
	make fclean 
	make all	

.PHONY : all clean fclean re