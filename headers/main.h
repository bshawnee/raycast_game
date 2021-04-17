#ifndef MAIN_H
# define MAIN_H

# include "../libs/mlx/mlx.h"
# include "parser.h"
# include <X11/X.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include "structs.h"


t_mlx	*create_mlx_win(int height, int width, const char *title);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
