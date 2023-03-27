NAME = so_long.a

SRCS =		so_long.c			\
			verif_map_utils.c	\
			verif_map_utils2.c	\
			algorithme.c		\
			check_maps.c		\

CC = gcc

FLAGS = -Wall -Wextra -Werror

AR = ar crs

RM = rm -f

LIBFT = libft

OBJS = ${SRCS:.c=.o}

.c.o:						${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:					${OBJS}
							make -C ${LIBFT}
							cp ./libft/libft.a ${NAME}
							${AR} ${NAME} ${OBJS}

all:						${NAME}

clean:
							${RM} ${OBJS}
							make fclean -C ${LIBFT}

fclean:		clean
							${RM} ${NAME}

re:							fclean all

.PHONY:						all clean fclean re