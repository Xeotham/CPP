#================ COMPILATOR ================#
CXX = c++
#=================== FLAGS ==================#
FLAGS = -g -Wall -Wextra -Werror -std=c++98
#=================== NAME ===================#
NAME = PhoneBook
#================== SOURCES =================#
SRCS =	Contact.cpp \
		PhoneBook.cpp \
		main.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean :
	rm -rf $(NAME) $(OBJS)

re : fclean all

.PHONY : all clean fclean re