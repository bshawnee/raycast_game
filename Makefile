NAME = cub3D
FLAGS = -Wall -Wextra -Werror -std=c99
LIBS =  libft/libft.a minilibx_opengl/libmlx.a
SRC =	gnl/get_next_line.c \
		utils/error.c \
		parser/take_path.c \
		parser/add_func.c \
		parser/take_map.c \
		parser/pars_color_resol.c \
		parser/pars_map.c \
		parser/parser.c \
		player/add_player.c \
		player/player.c \
		render/texture.c \
		render/render_utils.c \
		render/sprite.c \
		render/render.c \
		utils/bmp.c \
		game/game.c \
		main.c
OBJ_BONUS = bonus/main_bonus.c
OBJ = $(SRC:.c=.o)
HEADER =	parser/parser.h \
			player/player.h \
			cube3d.h \
			game/game.h \
			utils/utils.h \
			render/render.h \
			defines.h \
			global_var.h \
			structs.h \
			gnl/get_next_line.h

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(MAKE) -C ./minilibx_opengl
	gcc $(SRC) $(FLAGS) -framework OpenGL -framework AppKit $(LIBS) -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./minilibx_opengl
	rm -f screenshot.bmp
	rm -f $(OBJ)

fclean: clean
	rm -f libft/libft.a
	rm -f minilibx_opengl/libmlx.a
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME) map_configs/src_map.cub

norm:
	norminette $(SRC) $(HEADER)
	$(MAKE) norm -C ./libft
