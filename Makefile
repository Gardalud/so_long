NAME = so_long.a

SRCS =		so_long.c	\

CC = gcc

FLAGS = -Wall -Wextra -Werror

AR = ar crs

RM = rm -f

LIBFT = libft

FT_PRINTF = ft_printf

GNL = get_next_line

OBJS = ${SRCS:.c=.o}

.c.o:						${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:					${OBJS}
							make -C ${LIBFT}
							cp ./libft/libft.a ${NAME}
							make -C ${FT_PRINTF}
							cp ./ft_printf/libftprintf.a ${NAME}
							make -C ${GNL}
							cp ./get_next_line/libftgnl.a ${NAME}
							${AR} ${NAME} ${OBJS}

all:						${NAME}

clean:						${RM} ${OBJS}
							make fclean -C ${LIBFT}
							make fclean -C ${FT_PRINTF}
							make fclean -C ${GNL}

fclean:						clean
							${RM} ${NAME}

re:							clean fclean all

.PHONY:						all clean fclean re