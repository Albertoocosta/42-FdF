CC = cc -g
NAME = generate
MLX = minilibx-linux/libmlx.a
LIBFT = Libft/libft.a
PRINTF = Printf/libftprintf.a
FLAGS = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Wall -Werror -Wextra
SRCS = fdf.c 

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
re: clean all

.PHONY : all clean fclean re