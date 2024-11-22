#================ COMPILATOR ================#
CPP = c++
#=================== FLAGS ==================#
FLAGS = -g -Wall -Wextra -Werror -std=c++98
#=================== NAME ===================#
NAME = PhoneBook
#================== SOURCES =================#
SRCS =	tests.cpp \
		Account.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean :
	rm -rf $(NAME) $(OBJS)

re : fclean all

.PHONY : all clean fclean re