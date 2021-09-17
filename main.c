/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 16:11:16 by bshawnee          #+#    #+#             */
/*   Updated: 2021/03/15 18:15:04 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int		close_win(void *nil)
{
	if (!nil)
		exit(EXIT_SUCCESS);
	return (0);
}

static void		program_params(int argc, char **argv, int *save)
{
	if (argc <= 3 && argc > 1)
	{
		if (ft_strlen(argv[1]) < 4 || argv[1][ft_strlen(argv[1]) - 1] != 'b' \
		|| argv[1][ft_strlen(argv[1]) - 2] != 'u' || \
		argv[1][ft_strlen(argv[1]) - 3] != 'c' || \
		argv[1][ft_strlen(argv[1]) - 4] != '.')
			error("Cant unknwoun format file");
		g_map = pars_file(argv[1], &g_config);
		if (argc == 3)
		{
			if (!ft_strncmp("--save", argv[2], 7))
				*save = 1;
			else
				error("Unknown parametrs");
		}
	}
	else
		error("Enter norm parameters");
}

static void		check_scr_size(void)
{
	if (g_config.resolution[X] > 2560)
		g_config.resolution[X] = 2560;
	if (g_config.resolution[Y] > 1440)
		g_config.resolution[Y] = 1440;
}

int				main(int argc, char **argv)
{
	t_plr	player;
	int		save;

	g_map = NULL;
	save = 0;
	g_mlx.mlx_ptr = mlx_init();
	program_params(argc, argv, &save);
	pos_on_map((const char**)g_map, &player);
	check_scr_size();
	init_textures();
	g_mlx.win_ptr = mlx_new_window(g_mlx.mlx_ptr, g_config.resolution[0],
	g_config.resolution[1], "cub3D");
	update_frame(&player);
	if (save)
		save_image_bmp(&g_frame);
	ft_memset(&player.keys, 0, 8);
	mlx_put_image_to_window(g_mlx.mlx_ptr, g_mlx.win_ptr, g_frame.img, 0, 0);
	mlx_hook(g_mlx.win_ptr, X_WIN_CLOSE, KEY_PRESS, close_win, NULL);
	mlx_hook(g_mlx.win_ptr, 3, 2 << 1, unpress_b, &player);
	mlx_hook(g_mlx.win_ptr, 2, 1, key_press, &player);
	mlx_loop_hook(g_mlx.mlx_ptr, update_game, &player);
	mlx_loop(g_mlx.mlx_ptr);
	return (0);
}
