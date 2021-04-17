NAME = RunGame
SRC =	srcs/gnl/get_next_line.c \
		srcs/parser.c \
		srcs/utils.c \
		srcs/mlx_f.c \
		srcs/main.c
FLAGS = -g -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libs/mlx
	$(MAKE) -C ./libs/libft
	cp libs/mlx/libmlx.a .
	cp libs/libft/libft.a .
	$(CC) $(SRC) -I/mlx -L/mlx libmlx.a libft.a -lXext -lX11 -lm -lbsd $(FLAGS) -o $(NAME)

clean:
	$(MAKE) clean -C ./libs/mlx
	$(MAKE) clean -C ./libs/libft
	rm -f *.o libmlx.a libft.a
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)
