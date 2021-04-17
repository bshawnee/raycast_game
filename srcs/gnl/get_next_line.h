#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 32
# include <stdlib.h>
# include <fcntl.h>
# include "../../libs/libft/libft.h"
# include <unistd.h>

int		get_next_line(int fd, char **line);

#endif
