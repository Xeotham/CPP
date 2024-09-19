CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = 'Form up, maggots!'

SRCS =	main.cpp \
		Bureaucrat.cpp \
		Form.cpp

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