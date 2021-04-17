#include "../headers/main.h"

int		main(void)
{
	t_mlx *mlx = create_mlx_win(100, 300, "test");
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
