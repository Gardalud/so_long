NAME = so_long.a

SRCS = 

CC = gcc

FLAGS = -Wall -Wextra -Werror

AR = ar crs

RM = rm -rf

OBJS = {$SRCS:.c=.o}

.c.o:						${GCC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:					${OBJS}
							${AR} ${NAME} ${OBJS}

all:						${NAME}

clean:						${RM} ${OBJS}

fclean:						clean
							${RM} ${NAME}

re:							clean fclean

.PHONY:						all clean fclean re