NAME = fdf
CC = cc
FLAGS = -Wall -Wextra -Werror -g -fpie
MLX = minilibx-linux/libmlx.a
LIBFT = Libft/libft.a
PRINTF = Printf/libftprintf.a
SRCS = fdf.c utils.c make_draw.c processors.c utils2.c scaling_map.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(MLX):
	make --silent -C minilibx-linux

$(LIBFT):
	@make -C Libft

$(PRINTF):
	@make -C Printf

$(NAME): $(MLX) $(LIBFT) $(PRINTF) $(OBJS)
	@$(CC) $(FLAGS) $(MLX) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean: 
	@rm -rf *.o

fclean: clean
	@rm $(NAME)
	@echo ALL CLEAR

re: fclean all