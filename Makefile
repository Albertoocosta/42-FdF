NAME = fdf
CC = cc
FLAGS = -Wall -Wextra -Werror -g
SANFLAGS = -fsanitize=address -fsanitize=leak -fsanitize=undefined -fno-omit-frame-pointer
MLXFLAGS	= -lmlx -lXext -lX11 -lm
MLX = minilibx-linux/libmlx.a
LIBFT = Libft/libft.a
PRINTF = Printf/libftprintf.a
SRCS = fdf.c utils.c make_draw.c processors.c utils2.c scaling_map.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(MLX):
	@make -C minilibx-linux

$(LIBFT):
	@make -C Libft

$(PRINTF):
	@make -C Printf

$(NAME): $(OBJS) $(MLX) $(PRINTF) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS) -L$(MLXFLAGS) $(MLX) $(PRINTF) $(LIBFT) -o $(NAME)
 
%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean: 
	@rm -rf *.o Libft/*.o Printf/*.o

fclean: clean
	@rm $(NAME)
	@echo ALL CLEAR

re: fclean all