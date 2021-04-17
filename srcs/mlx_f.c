#include "../headers/main.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_mlx	*create_mlx_win(int height, int width, const char *title)
{
	t_mlx *mlx;

	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		error("Error. Not enough memory");
	if (!(mlx->mlx_ptr = mlx_init()))
		error("Error. Can't run mlx");
	if (!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, width, height, (char*)title)))
		error("Error. Cant create window");
	return (mlx);
}
