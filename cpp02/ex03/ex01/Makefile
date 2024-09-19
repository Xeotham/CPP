CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Towards_a_more_useful_fixed-point_number_class

SRCS = main.cpp \
	Fixed.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean :
	rm -rf $(NAME) $(OBJS)

re : fclean all

.PHONY : all clean fclean re