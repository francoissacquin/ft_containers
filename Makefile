NAME = containers
NAME_STD = std_containers
NAME_FT = ft_containers

CC = clang++

SRCS = ./test_mains/vector_main.cpp

SRCS_TIME = ./test_mains/time_benchmark_vector.cpp

INC = ./vector/equal.hpp \
 ./vector/lexicographical_compare.hpp \
 ./vector/random_access_iterator.hpp \
 ./vector/vector.hpp \
 ./vector/is_integral.hpp \
 ./vector/enable_if.hpp


CFLAGS = -Wall -Wextra -Werror -std=c++98 -I. #-fsanitize=address -g3

OBJS := ${SRCS:.cpp=.o}

OBJS_TIME := ${SRCS_TIME:.cpp=.o}

all : ${NAME}

${NAME} : ${OBJS}
			$(CC) $(CFLAGS) -D STD -o $(NAME_STD) $^
			$(CC) $(CFLAGS) -o $(NAME_FT) $^

time:	${OBJS_TIME}
			$(CC) $(CFLAGS) -D STD -o $(NAME_STD) $^
			$(CC) $(CFLAGS) -o $(NAME_FT) $^

%.o: %.cpp
		$(CC) $(CFLAGS) -o $@ -c $<
clean :
		rm -rf ${OBJS}

fclean : clean
			rm -rf ${NAME} ${NAME_STD} ${NAME_FT}

re	:	fclean all

.PHONY : clean fclean re
