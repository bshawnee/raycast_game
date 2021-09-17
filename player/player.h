/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:42:54 by bshawnee          #+#    #+#             */
/*   Updated: 2021/03/15 18:13:44 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include <math.h>
# include "../libft/libft.h"
# include "../global_var.h"
# include "../defines.h"

int		unpress_b(int k, t_plr *plr);
void	add_move(t_plr *p);
void	move_up_down(t_plr *p);
void	pos_on_map(const char **matrix, t_plr *player);
void	player_movement(t_plr *p, const char **map);

#endif
