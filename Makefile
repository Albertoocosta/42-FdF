CC = cc -g
NAME = generate
MLX = minilibx-linux/libmlx.a
FLAGS = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Wall -Werror -Wextra
SRCS = fdf.c 

all: ${NAME}

${MLX}:
	make --silent -C minilibx-linux

${NAME}: ${MLX}
	${CC} ${SRCS} ${MLX} ${FLAGS} -o ${NAME}

clean:
	@rm ${NAME}

re: fclean all

.PHONY : all clean fclean re