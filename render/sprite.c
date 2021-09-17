/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:34:44 by bshawnee          #+#    #+#             */
/*   Updated: 2021/02/27 12:13:09 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "../global_var.h"
#include "../structs.h"
#include <printf.h>

int				g_real_text_s;
int				g_text_x;

void			vert_line(int x, int draw_s, int draw_end, int w)
{
	char	*clr;
	int		current_text_s;
	int		y;

	current_text_s = draw_end - draw_s;
	while (draw_s != draw_end)
	{
		y = g_sprite_text.height * (((g_real_text_s + current_text_s) \
		>> 1) - (draw_end - draw_s)) / g_real_text_s;
		clr = g_sprite_text.img.addr + (y *
		g_sprite_text.img.line_length + w * 4);
		if (*(unsigned*)clr != 0x980088)
			my_mlx_pixel_put(&g_frame, x, draw_s, *(unsigned*)clr);
		draw_s++;
	}
}

void			check_valid(int *num, int *num2, int limit)
{
	if (*num < 0)
		*num = 0;
	if (*num2 > limit)
		*num2 = limit - 1;
}

static int		init_sprite(double *t_form, int *sprite)
{
	sprite[Y] = fabs(g_config.resolution[Y] / t_form[Y]);
	sprite[X] = fabs(g_config.resolution[X] / t_form[Y]);
	return (g_config.resolution[X] / 2) * (1 + t_form[X] / t_form[Y]);
}

static void		text_resolution(double *t_form, double *zbuff)
{
	double	spr_scrn_x;
	int		sprite[2];
	int		draw[2][2];

	spr_scrn_x = init_sprite(t_form, sprite);
	sprite[Y] = fabs(g_config.resolution[Y] / t_form[Y]);
	draw[Y][START] = -sprite[Y] / 2 + g_config.resolution[Y] / 2;
	draw[Y][END] = sprite[Y] / 2 + g_config.resolution[Y] / 2;
	g_real_text_s = draw[Y][END] - draw[Y][START];
	check_valid(&draw[Y][START], &draw[Y][END], g_config.resolution[Y]);
	sprite[X] = fabs(g_config.resolution[X] / t_form[Y]);
	draw[X][START] = -sprite[X] / 2 + spr_scrn_x;
	draw[X][END] = sprite[X] / 2 + spr_scrn_x;
	check_valid(&draw[X][START], &draw[X][END], g_config.resolution[X]);
	while (draw[X][START] < draw[X][END])
	{
		if (t_form[Y] > 0 && draw[X][START] > 0 && draw[X][START] <
		g_config.resolution[X] && t_form[Y] < zbuff[draw[X][START]])
		{
			g_text_x = ((256 * (draw[X][START] - (-sprite[X] / 2 + spr_scrn_x))
			* g_sprite_text.width / sprite[X]) / 256);
			vert_line(draw[X][START], draw[Y][START], draw[Y][END], g_text_x);
		}
		draw[X][START]++;
	}
}

void			init_sprites(t_sprite *s, t_plr *plr, double *zbuffer)
{
	double	sprite[2];
	double	inv_det;
	double	transform[2];

	sort_sprite(&s, plr->pos_x, plr->pos_y);
	while (s)
	{
		sprite[X] = s->x - plr->pos_x;
		sprite[Y] = s->y - plr->pos_y;
		inv_det = 1.0 / (plr->plane_x * plr->dir_y - plr->dir_x * plr->plane_y);
		transform[X] = inv_det * (sprite[X] * plr->dir_y - sprite[Y] *
		plr->dir_x);
		transform[Y] = inv_det * (-plr->plane_y * sprite[X] + plr->plane_x *
		sprite[Y]);
		text_resolution(transform, zbuffer);
		s = s->next;
	}
}
