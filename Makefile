NAME = so_long.a

SRCS =		so_long.c			\
			verif_map_utils.c	\
			verif_map_utils2.c	\
			algorithme.c		\
			check_maps.c		\
			image.c				\

CC = gcc

FLAGS = -Wall -Wextra -Werror

AR = ar crs

RM = rm -f

#######################################
#   MLX 

MLXLIB = ./mlx/libmlx.a
MLX = ./mlx
MLX_C = make -C ${MLX}

MINILBX = -Lmlx -lmlx -framework OpenGL -framework AppKit

#######################################

# libft

LIBFTLIB = ./libft/libft.a
LIBFT = ./libft
LIBFT_C = make -C ${LIBFT}

########################################

OBJS = ${SRCS:.c=.o}

.c.o:
							${CC} ${FLAGS} -c $< -o $@

${NAME}:					${OBJS} ${MLXLIB} ${LIBFTLIB}
							${AR} ${NAME} ${OBJS}
							${CC} ${FLAGS} ${LIBFTLIB} ${MINILBX} ${NAME} 
#							-o so_long

${LIBFTLIB}:
							${LIBFT_C}

${MLXLIB}:
							${MLX_C}

all:						${NAME}

clean:
							${RM} ${OBJS}
							make fclean -C ${LIBFT}
							make clean -C ${MLX}

fclean:		clean
							${RM} ${NAME}

re:							fclean all

.PHONY:						all clean fclean re