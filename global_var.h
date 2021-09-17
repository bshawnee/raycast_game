/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_var.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 18:55:48 by bshawnee          #+#    #+#             */
/*   Updated: 2021/02/27 12:33:07 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_VAR_H
# define GLOBAL_VAR_H
# include "structs.h"

t_sprite			*g_sprite;
t_img				g_frame;
t_mlx				g_mlx;
char				**g_map;
int					g_side;
t_config			g_config;
t_plr				*g_player;
unsigned			g_sprite_count;
t_picture			g_sprite_text;
double				g_raydir_x;
double				g_raydir_y;

#endif
