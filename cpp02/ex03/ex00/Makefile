CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = My_First_Class_in_Orthodox_Canonical_Form

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