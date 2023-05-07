NAME = so_long.a

SRCS =		so_long.c			\
			verif_map_utils.c	\
			verif_map_utils2.c	\
			algorithme.c		\
			check_maps.c		\
			image.c				\
			play_game.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

AR = ar crs

RM = rm -f

#######################################
# Couleurs

RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
RESET=\033[0m

#######################################
# MLX

MLXLIB = ./mlx/libmlx.a
MLX = ./mlx
MLX_C = make -C ${MLX}

MINILBX = -Lmlx -lmlx -framework OpenGL -framework AppKit

#######################################
# Libft

LIBFTLIB = ./libft/libft.a
LIBFT = ./libft
LIBFT_C = make -C ${LIBFT}

########################################

OBJS = ${SRCS:.c=.o}

.c.o:
	@${CC} ${FLAGS} -c $< -o $@
	@echo "${GREEN}[OK]${RESET} Compilation de $<"

${NAME}:	${OBJS} ${MLXLIB} ${LIBFTLIB}
	@${AR} ${NAME} ${OBJS}
	@${CC} ${FLAGS} ${LIBFTLIB} ${MINILBX} ${NAME} -o so_long
	@echo "${GREEN}[OK]${RESET} Compilation terminée : ${BLUE}so_long${RESET}"

${LIBFTLIB}:
	@${LIBFT_C}

${MLXLIB}:
	@${MLX_C}

all:	${NAME}

clean:
	@${RM} ${OBJS}
	@make fclean -C ${LIBFT}
	@make clean -C ${MLX}
	@echo "${GREEN}[OK]${RESET} Nettoyage terminé"

fclean:	clean
	@${RM} ${NAME}
	@${RM} so_long
	@echo "${GREEN}[OK]${RESET} Nettoyage complet"

re:		fclean all

.PHONY:	all clean fclean re