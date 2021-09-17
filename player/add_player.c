/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 00:12:59 by bshawnee          #+#    #+#             */
/*   Updated: 2021/03/15 18:18:52 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

int			check_collis(int y, int x)
{
	if (g_map[y][x] != '1' && g_map[y][x] && g_map[y][x] != ' ')
		return (1);
	return (0);
}

void		add_move(t_plr *p)
{
	double y;
	double x;

	if (p->keys.m_up)
	{
		y = PLAYER_SPEED * 1.5 * p->dir_x + p->pos_x;
		x = p->pos_y + p->dir_y * (PLAYER_SPEED * 2);
		if (check_collis((int)y, (int)x))
		{
			p->pos_y += p->dir_y * PLAYER_SPEED;
			p->pos_x += p->dir_x * PLAYER_SPEED;
		}
	}
	if (p->keys.m_down)
	{
		y = p->pos_x - p->dir_x * (PLAYER_SPEED * 2);
		x = p->pos_y - p->dir_y * (PLAYER_SPEED * 2);
		if (check_collis((int)y, (int)x))
		{
			p->pos_x -= p->dir_x * PLAYER_SPEED;
			p->pos_y -= p->dir_y * PLAYER_SPEED;
		}
	}
}

void		move_up_down(t_plr *p)
{
	double y;
	double x;

	add_move(p);
	if (p->keys.m_r)
	{
		y = p->pos_x + PLAYER_SPEED * 2 * p->dir_y;
		x = p->pos_y - PLAYER_SPEED * 2 * p->dir_x;
		if (check_collis((int)y, (int)x))
		{
			p->pos_x += p->dir_y * PLAYER_SPEED;
			p->pos_y -= p->dir_x * PLAYER_SPEED;
		}
	}
	if (p->keys.m_l)
	{
		y = p->pos_x - PLAYER_SPEED * 2 * p->dir_y;
		x = p->pos_y + p->dir_x * PLAYER_SPEED * 2;
		if (check_collis((int)y, (int)x))
		{
			p->pos_x -= p->dir_y * PLAYER_SPEED;
			p->pos_y += p->dir_x * PLAYER_SPEED;
		}
	}
}

int			unpress_b(int k, t_plr *plr)
{
	if (k == KEY_A)
		plr->keys.m_l = 0;
	if (k == KEY_D)
		plr->keys.m_r = 0;
	if (k == KEY_W)
		plr->keys.m_up = 0;
	if (k == KEY_S)
		plr->keys.m_down = 0;
	if (k == KEY_LEFT)
		plr->keys.pov_l = 0;
	if (k == KEY_RIGHT)
		plr->keys.pov_r = 0;
	return (0);
}
