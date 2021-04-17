NAME = libft.a
FLAGS = -Wall -Wextra -Werror -std=c99
SRC =	ft_strlen.c \
		ft_strjoin.c \
		ft_memset.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_isascii.c \
		ft_atoi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_bzero.c \
		ft_substr.c \
		ft_split.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memmove.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_memcmp.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_strlcpy.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_strmapi.c

B_SRC = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c

B_OBJ = $(B_SRC:.c=.o)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ) $(B_OBJ)

fclean: clean
	rm -f $(NAME)

bonus:
	CC $(FLAGS) $(SRC) $(B_SRC) -c
	ar -rcs $(NAME) $(OBJ) $(B_OBJ)
	ranlib $(NAME)

run: all
	gcc $(NAME) $(FLAGS) main.c -g
	./a.out

norm:
	norminette $(SRC) libft.h

re: fclean all
