CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = Moar_brainz!

SRCS = main.cpp \
	Zombie.cpp \
	zombieHorde.cpp
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