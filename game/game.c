/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 22:35:37 by bshawnee          #+#    #+#             */
/*   Updated: 2021/03/15 18:13:31 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int				update_game(t_plr *plr)
{
	if (plr->keys.esc)
		exit(0);
	player_movement(plr, (const char**)g_map);
	update_frame(plr);
	mlx_put_image_to_window(g_mlx.mlx_ptr, g_mlx.win_ptr, g_frame.img, 0, 0);
	return (0);
}

int				key_press(int keycode, t_plr *plr)
{
	if (keycode == KEY_A)
		plr->keys.m_l = 1;
	if (keycode == KEY_D)
		plr->keys.m_r = 1;
	if (keycode == KEY_S)
		plr->keys.m_down = 1;
	if (keycode == KEY_W)
		plr->keys.m_up = 1;
	if (keycode == KEY_RIGHT)
		plr->keys.pov_r = 1;
	if (keycode == KEY_LEFT)
		plr->keys.pov_l = 1;
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}
