NAME = containers

CC = clang++

SRCS = ./vector_main.cpp

INC = ./vector/equal.hpp \
 ./vector/lexicographical_compare.hpp \
 ./vector/random_access_iterator.hpp \
 ./vector/vector.hpp \
 ./vector/is_integral.hpp \
 ./vector/enable_if.hpp


CFLAGS = -Wall -Wextra -Werror -std=c++98 -I. #-fsanitize=address -g3

OBJS := ${SRCS:.cpp=.o}

all : ${NAME}

${NAME} : ${OBJS}
			$(CC) $(CFLAGS) -o $(NAME) $^

%.o: %.cpp
		$(CC) $(CFLAGS) -o $@ -c $<
clean :
		rm -rf ${OBJS}

fclean : clean
			rm -rf ${NAME}

re	:	fclean all

.PHONY : clean fclean re
