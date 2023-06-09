NAME = so_long.a

SRCS =		so_long.c			\
			verif_map_utils.c	\
			verif_map_utils2.c	\
			algorithme.c		\
			check_maps.c		\
			image.c				\
			play_game.c			\
			play_game2.c		\

CC = gcc

FLAGS = -Wall -Wextra -Werror

AR = ar crs

RM = rm -f

#######################################

RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
RESET=\033[0m

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
							@${CC} ${FLAGS} -c $< -o $@ > /dev/null

${NAME}:					${OBJS} ${MLXLIB} ${LIBFTLIB}
							@${AR} ${NAME} ${OBJS} > /dev/null
							@${CC} ${FLAGS} ${LIBFTLIB} ${MINILBX} ${NAME} -o so_long 2> /dev/null
							@echo "${YELLOW} Compilation réussie:${GREEN}[ok] ${RESET}"

${LIBFTLIB}:
							@${LIBFT_C} > /dev/null
							@echo "${YELLOW} Compilation libft:${GREEN}[ok] ${RESET}"

${MLXLIB}:
							@${MLX_C} > /dev/null
							@echo "${YELLOW} Compilation MLX:${GREEN}[ok] ${RESET}"

all:						${NAME}

clean:
							@${RM} ${OBJS} > /dev/null
							@make fclean -C ${LIBFT} > /dev/null
							@make clean -C ${MLX} > /dev/null
							@echo "${YELLOW} Nettoyage libft:${GREEN}[ok] ${RESET}"
							@echo "${YELLOW} Nettoyage MLX:${GREEN}[ok] ${RESET}"

fclean:		clean
							@${RM} ${NAME} > /dev/null
							@${RM} so_long >/dev/null
							@echo "${YELLOW} Nettoyage complet de so_long:${GREEN}[ok] ${RESET}"

re:							fclean all

.PHONY:						all clean fclean re   