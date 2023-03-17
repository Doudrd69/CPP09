CC = c++
FLAGS = -Wall -Wextra -Werror

SRCS =	main.cpp			\
		RPN.cpp


INCS =	RPN.hpp

OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp $(INCS)
	$(CC) $(FLAGS) -std=c++98 -c $< -o $@

NAME = RPN

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) -I $(INCS) -std=c++98 -o $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re