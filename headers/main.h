#ifndef MAIN_H
# define MAIN_H

# include "../mlx/mlx.h"
# include <X11/X.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_mlx;

void	error(const char *msg);
t_mlx	*create_mlx_win(int height, int width, const char *title);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
