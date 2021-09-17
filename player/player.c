/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:50:49 by bshawnee          #+#    #+#             */
/*   Updated: 2021/03/15 18:46:09 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "../utils/utils.h"

int				g_count[2];
int				g_count_pos;

static void		move_right_left(t_plr *p)
{
	double old_dir_x;
	double old_plane;

	old_dir_x = p->dir_x;
	if (p->keys.pov_r)
	{
		p->dir_x = p->dir_x * cos(-SENSETIVE) - p->dir_y * sin(-SENSETIVE);
		p->dir_y = old_dir_x * sin(-SENSETIVE) + p->dir_y * cos(-SENSETIVE);
		old_plane = p->plane_x;
		p->plane_x = p->plane_x * cos(-SENSETIVE) - p->plane_y *
		sin(-SENSETIVE);
		p->plane_y = old_plane * sin(-SENSETIVE) + p->plane_y * cos(-SENSETIVE);
	}
	if (p->keys.pov_l)
	{
		p->dir_x = p->dir_x * cos(SENSETIVE) - p->dir_y * sin(SENSETIVE);
		p->dir_y = old_dir_x * sin(SENSETIVE) + p->dir_y * cos(SENSETIVE);
		old_plane = p->plane_x;
		p->plane_x = p->plane_x * cos(SENSETIVE) - p->plane_y * sin(SENSETIVE);
		p->plane_y = old_plane * sin(SENSETIVE) + p->plane_y * cos(SENSETIVE);
	}
}

void			rotate_player(const char pos, t_plr *plr)
{
	if (pos == 'S')
	{
		plr->plane_y = -0.66;
		plr->dir_x = 1;
	}
	else if (pos == 'E')
	{
		plr->plane_x = 0.66;
		plr->plane_y = 0;
		plr->dir_x = 0;
		plr->dir_y = 1;
	}
	else if (pos == 'W')
	{
		plr->plane_x = -0.66;
		plr->plane_y = 0;
		plr->dir_x = 0;
		plr->dir_y = -1;
	}
}

void			pos_on_map(const char **matrix, t_plr *player)
{
	player->plane_x = 0;
	player->plane_y = 0.66;
	player->dir_x = -1;
	player->dir_y = 0;
	while (matrix[g_count[0]])
	{
		g_count[1] = 0;
		while (matrix[g_count[0]][g_count[1]])
		{
			if (ft_strchr("NSWE", matrix[g_count[0]][g_count[1]]) &&
			ft_strncmp("SKIP", matrix[g_count[0]], 5))
			{
				g_count_pos++;
				player->pos_x = (float)g_count[0] + 0.5;
				player->pos_y = (float)g_count[1] + 0.5;
				rotate_player(matrix[g_count[0]][g_count[1]], player);
			}
			else if (matrix[g_count[0]][g_count[1]] == '2')
				g_sprite_count++;
			g_count[1]++;
		}
		g_count[0]++;
	}
	if ((g_count_pos == 0 || g_count_pos > 1))
		error("Too many players on map");
}

void			player_movement(t_plr *p, const char **map)
{
	if (!map)
		return ;
	move_right_left(p);
	move_up_down(p);
}
