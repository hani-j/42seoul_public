CXX = c++
CXXFLAGS = -Werror -Wall -Wextra -std=c++98
NAME = convert

SRCS = main.cpp \
		Conversion.cpp \

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : 
	make fclean 
	make all	

.PHONY : all clean fclean re
