CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = BraiiiiiiinnnzzzZ

SRCS = main.cpp \
	newZombie.cpp \
	randomChump.cpp \
	Zombie.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CPP) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean :
	rm -rf $(NAME) $(OBJS)

re : fclean all

.PHONY : all clean fclean re