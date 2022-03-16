NAME = containers
NAME_STD = std_containers
NAME_FT = ft_containers

CC = clang++

SRCS = ./test_mains/vector_main.cpp

SRCS_VECTOR = ./test_mains/vector_main.cpp

SRCS_MAP = ./test_mains/map_main.cpp

SRCS_STACK = ./test_mains/stack_main.cpp

SRCS_SET = ./test_mains/set_main.cpp

SRCS_TIME = ./test_mains/time_benchmark_vector.cpp

INC = ./vector/equal.hpp \
 ./vector/lexicographical_compare.hpp \
 ./vector/random_access_iterator.hpp \
 ./vector/vector.hpp \
 ./vector/is_integral.hpp \
 ./vector/enable_if.hpp


CFLAGS = -Wall -Wextra -Werror -std=c++98 -I. -g #-fsanitize=address -g3

OBJS := ${SRCS:.cpp=.o}

OBJS_VECTOR := ${SRCS_VECTOR:.cpp=.o}

OBJS_MAP := ${SRCS_MAP:.cpp=.o}

OBJS_STACK:= ${SRCS_STACK:.cpp=.o}

OBJS_SET:= ${SRCS_SET:.cpp=.o}

OBJS_TIME := ${SRCS_TIME:.cpp=.o}

all : ${NAME}

${NAME} : ${OBJS}
			$(CC) $(CFLAGS) -D STD -o $(NAME_STD) ${SRCS}
			$(CC) $(CFLAGS) -o $(NAME_FT) ${SRCS}

vector : ${OBJS_VECTOR}
			$(CC) $(CFLAGS) -D STD -o std_vector ${SRCS_VECTOR}
			$(CC) $(CFLAGS) -o ft_vector ${SRCS_VECTOR}

map : ${OBJS_MAP}
			$(CC) $(CFLAGS) -D STD -o std_map ${SRCS_MAP}
			$(CC) $(CFLAGS) -o ft_map ${SRCS_MAP}

stack : ${OBJS_STACK}
			$(CC) $(CFLAGS) -D STD -o std_stack ${SRCS_STACK}
			$(CC) $(CFLAGS) -o ft_stack ${SRCS_STACK}

set_ : ${OBJS_SET}
			$(CC) $(CFLAGS) -D STD -o std_set ${SRCS_SET}
			$(CC) $(CFLAGS) -o ft_set ${SRCS_SET}

time_bench:	${OBJS_TIME}
			$(CC) $(CFLAGS) -D STD -o $(NAME_STD) ${SRCS_TIME}
			$(CC) $(CFLAGS) -o $(NAME_FT) ${SRCS_TIME}

%.o: %.cpp
		$(CC) $(CFLAGS) -o $@ -c $<

clean :
		rm -rf ${OBJS} ${OBJS_VECTOR} ${OBJS_MAP} ${OBJS_STACK} ${OBJS_TIME} ${OBJS_SET}

fclean : clean
			rm -rf ${NAME} ${NAME_STD} ${NAME_FT} std_vector ft_vector std_map ft_map std_stack ft_stack std_set ft_set

re	:	fclean all

.PHONY : clean fclean re
