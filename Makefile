CC = cc -g
NAME = generate
MLX = minilibx-linux/libmlx.a
LIBFT = Libft/libft.a
PRINTF = Printf/libftprintf.a
FLAGS = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Wall -Werror -Wextra -no-pie
SRCS = fdf.c utils.c makeDraw.c key_handler.c utils2.c

all: ${NAME}

${MLX}:
	make --silent -C minilibx-linux

${LIBFT}:
	make --silent -C Libft

${PRINTF}:
	make --silent -C Printf

${NAME}: ${MLX} ${LIBFT} ${PRINTF}
	${CC} ${SRCS} ${MLX} ${LIBFT} ${PRINTF} ${FLAGS} -o ${NAME}

clean:
	@rm ${NAME}
	@echo ALL CLEAR
re: clean all
