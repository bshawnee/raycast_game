/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 20:50:47 by bshawnee          #+#    #+#             */
/*   Updated: 2021/03/11 21:10:56 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "../parser/parser.h"

t_picture	g_walls[4];
unsigned	g_r_wall_s;
int			g_wall_s;

static char			*texture(unsigned tex_w, int current_y, t_picture *wall, \
					int draw_end)
{
	int y;

	y = wall->height * (((g_wall_s + g_r_wall_s) >> 1) -
	(draw_end - current_y)) / g_r_wall_s;
	return (wall->img.addr + (y * wall->img.line_length + tex_w * 4));
}

void				ver_line(int x, int draw_s, int draw_end, double tex_w)
{
	char *clr;

	g_wall_s = draw_end - draw_s;
	if (draw_s > draw_end)
		return ;
	while (draw_s < draw_end)
	{
		if (!g_side)
		{
			clr = texture(tex_w, draw_s, &g_walls[0], draw_end);
			if (g_raydir_x < 0)
				clr = texture(tex_w, draw_s, &g_walls[2], draw_end);
		}
		else
		{
			clr = texture(tex_w, draw_s, &g_walls[1], draw_end);
			if (g_raydir_y < 0)
				clr = texture(tex_w, draw_s, &g_walls[3], draw_end);
		}
		my_mlx_pixel_put(&g_frame, x, draw_s, *(unsigned int*)clr);
		draw_s++;
	}
}

void				print_line(double perp_wall_dist, int x)
{
	double	wall_x;
	int		draw_start;
	int		draw_end;
	int		line_h;

	line_h = (int)(g_config.resolution[Y] / perp_wall_dist);
	draw_start = -line_h / 2 + g_config.resolution[Y] / 2;
	draw_end = line_h / 2 + g_config.resolution[Y] / 2;
	g_r_wall_s = draw_end - draw_start;
	if (draw_start < 0 || draw_start > g_config.resolution[Y])
		draw_start = 0;
	if (draw_end >= g_config.resolution[Y] || draw_end < 0)
		draw_end = g_config.resolution[Y] - 1;
	if (!g_side)
		wall_x = g_player->pos_y + perp_wall_dist * g_raydir_y;
	else
		wall_x = g_player->pos_x + perp_wall_dist * g_raydir_x;
	wall_x -= floor(wall_x);
	ver_line(x, draw_start, draw_end, g_walls[0].width * wall_x);
}

void				update_frame(t_plr *plr)
{
	int		x;
	int		map[2];
	double	perp_w_dist;
	int		step[2];
	double	*zbuffer;

	g_player = plr;
	x = 0;
	zbuffer = (double*)malloc(sizeof(double) * g_config.resolution[X] + 1);
	render_background();
	while (x < g_config.resolution[X])
	{
		g_player->camera_x = 2 * x / (double)g_config.resolution[X] - 1;
		g_raydir_x = g_player->dir_x + g_player->plane_x * g_player->camera_x;
		g_raydir_y = g_player->dir_y + g_player->plane_y * g_player->camera_x;
		map[X] = (int)g_player->pos_x;
		map[Y] = (int)g_player->pos_y;
		raycaster(map, step);
		perp_w_dist = perp_wall_dist(step, map);
		print_line(perp_w_dist, x);
		x++;
		zbuffer[x] = perp_w_dist;
	}
	init_sprites(g_sprite, plr, zbuffer);
	free(zbuffer);
}

int					init_textures(void)
{
	init_sprite_mem();
	g_frame.img = mlx_new_image(g_mlx.mlx_ptr, g_config.resolution[X],
	g_config.resolution[Y]);
	g_frame.addr = mlx_get_data_addr(g_frame.img, &g_frame.bits_per_pixel,
	&g_frame.line_length, &g_frame.endian);
	if (init_texture(&g_walls[0], g_config.north_texture) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	if (init_texture(&g_walls[2], g_config.south_texture) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	if (init_texture(&g_walls[1], g_config.west_texture) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	if (init_texture(&g_walls[3], g_config.east_texture) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	if (init_texture(&g_sprite_text, g_config.sprite_texture) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	return (0);
}
