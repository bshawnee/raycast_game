NAME = RunGame
SRC =	srcs/utils.c \
		srcs/mlx_f/mlx_f.c \
		srcs/main.c
FLAGS = -g
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./mlx
	cp mlx/libmlx.a .
	$(CC) -libmlx.a -I/mlx -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) -L/mlx libmlx.a  -lXext -lX11 -lm -lbsd

clean:
	$(MAKE) clean -C ./mlx
	rm -f *.o libmlx.a
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)
