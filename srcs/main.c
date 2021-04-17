#include "../headers/main.h"

static char		**program_params(int argc, char **argv, int *save, t_config *config)
{
	char **map = NULL;
	if (argc <= 3 && argc > 1)
	{
		if (ft_strlen(argv[1]) < 4 || argv[1][ft_strlen(argv[1]) - 1] != 'b' \
		|| argv[1][ft_strlen(argv[1]) - 2] != 'u' || \
		argv[1][ft_strlen(argv[1]) - 3] != 'c' || \
		argv[1][ft_strlen(argv[1]) - 4] != '.')
			error("Unknwoun config file format");
		map = pars_file(argv[1], config);
		if (argc == 3)
		{
			if (!ft_strncmp("--save", argv[2], 7))
				*save = 1;
			else
				error("Unknown parametrs");
		}
	}
	else
		error("Invalid number of parameters");
	return (map);
}

int		close_win(void *nul)
{
	if (!nul)
		exit(0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_config	conf;
	int			save = 0;

	program_params(argc, argv, &save, &conf);
	t_mlx *mlx = create_mlx_win(conf.resolution[0], conf.resolution[1], "test");
	mlx_hook(mlx->mlx_ptr, LeaveNotify, KeyPressMask, close_win, NULL);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
