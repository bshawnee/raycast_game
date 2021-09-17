/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 11:52:38 by bshawnee          #+#    #+#             */
/*   Updated: 2021/03/12 00:28:02 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	new_elem_list(unsigned x, unsigned y)
{
	t_sprite *tmp;

	if (!g_sprite)
	{
		if (!(g_sprite = (t_sprite*)malloc(sizeof(t_sprite))))
			return ;
		g_sprite->x = x + 0.5;
		g_sprite->y = y + 0.5;
		g_sprite->next = NULL;
		return ;
	}
	tmp = g_sprite;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = (t_sprite*)malloc(sizeof(t_sprite));
	tmp->next->x = x + 0.5;
	tmp->next->y = y + 0.5;
	tmp->next->next = NULL;
}

void		init_sprite_mem(void)
{
	unsigned i;
	unsigned j;

	i = 0;
	while (g_map[i])
	{
		j = 0;
		while (g_map[i][j])
		{
			if (g_map[i][j] == '2')
				new_elem_list(i, j);
			j++;
		}
		i++;
	}
}

void		side_distance(int *step, double *sidedist, double *deltadist, \
			int *map)
{
	if (g_raydir_x < 0)
	{
		step[X] = -1;
		sidedist[X] = (g_player->pos_x - map[X]) * deltadist[X];
	}
	else
	{
		step[X] = 1;
		sidedist[X] = (map[X] + 1.0 - g_player->pos_x) * deltadist[X];
	}
	if (g_raydir_y < 0)
	{
		step[Y] = -1;
		sidedist[Y] = (g_player->pos_y - map[Y]) * deltadist[Y];
	}
	else
	{
		step[Y] = 1;
		sidedist[Y] = (map[Y] + 1.0 - g_player->pos_y) * deltadist[Y];
	}
}

void		raycaster(int *map, int *step)
{
	double side_dist[2];
	double delta_dist[2];

	delta_dist[X] = fabs(1 / g_raydir_x);
	delta_dist[Y] = fabs(1 / g_raydir_y);
	side_distance(step, side_dist, delta_dist, map);
	while (g_map[map[X]][map[Y]] != '1')
	{
		if (side_dist[X] < side_dist[Y])
		{
			side_dist[X] += delta_dist[X];
			map[X] += step[X];
			g_side = 0;
		}
		else
		{
			side_dist[Y] += delta_dist[Y];
			map[Y] += step[Y];
			g_side = 1;
		}
	}
}

double		perp_wall_dist(int *step, int *map)
{
	if (!g_side)
		return ((map[X] - g_player->pos_x + (1 - step[X]) / 2) / g_raydir_x);
	else
		return ((map[Y] - g_player->pos_y + (1 - step[Y]) / 2) / g_raydir_y);
}
