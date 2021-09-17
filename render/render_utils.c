/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 11:03:14 by bshawnee          #+#    #+#             */
/*   Updated: 2021/03/11 20:17:41 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void				my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * 4);
	*(unsigned int*)dst = color;
}

static void			swap_num(double *src, double *dest)
{
	double tmp;

	tmp = *src;
	*src = *dest;
	*dest = tmp;
}

void				sort_sprite(t_sprite **s, double pos_x, double pos_y)
{
	t_sprite	*start_list;
	double		dist_current;
	double		dist_next;

	start_list = *s;
	while ((*s))
	{
		if (!(*s)->next)
			break ;
		dist_current = (pos_x - (*s)->x) * (pos_x - (*s)->x) + (pos_y - \
		(*s)->y) * (pos_y - (*s)->y);
		dist_next = (pos_x - (*s)->next->x) * (pos_x - (*s)->next->x) + \
		(pos_y - (*s)->next->y) * (pos_y - (*s)->next->y);
		if (dist_current < dist_next)
		{
			swap_num(&(*s)->x, &(*s)->next->x);
			swap_num(&(*s)->y, &(*s)->next->y);
			(*s) = start_list;
		}
		else
			(*s) = (*s)->next;
	}
	(*s) = start_list;
}

void				render_background(void)
{
	int i;
	int j;

	i = 0;
	while (i < g_config.resolution[Y])
	{
		j = 0;
		while (j < g_config.resolution[X])
		{
			if (i < g_config.resolution[Y] / 2)
				my_mlx_pixel_put(&g_frame, j, i, \
				convert_rgb_to_hex(&g_config.skybox_color));
			else
				my_mlx_pixel_put(&g_frame, j, i, \
				convert_rgb_to_hex(&g_config.floor_color));
			j++;
		}
		i++;
	}
}

int					init_texture(t_picture *texture, const char *filename)
{
	if ((texture->img.img = mlx_xpm_file_to_image(g_mlx.mlx_ptr, (char*)\
	filename, &texture->width, &texture->height)) <= 0)
		error("Cant open texture");
	texture->img.addr = mlx_get_data_addr(texture->img.img,
	&texture->img.bits_per_pixel, &texture->img.line_length,
	&texture->img.endian);
	return (0);
}
